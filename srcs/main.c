/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:30:39 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/04 18:10:24 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_conf	g_sh;

void	exit_shell(int num)
{
	printf("Good bye ~ !\n");
	exit(num);
}

void	print_token(t_lst *token)
{
	t_token	*temp;

	temp = token->head;
	while (temp)
	{
		printf("token = %s, type = %c, index = %d\n",
				temp->token,
				temp->type,
				temp->i);
		temp = temp->next;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	analyze_space(t_lexer *lexer, int i)
{
	if (!lexer)
		return ;
	if (lexer->s_quote > TRUE)
		lexer->lex[i] = ' ';
	else if (lexer->s_quote == FALSE)
		lexer->lex[i] = 's';
}

void	analyze_quote_pair(t_lexer *lexer, char c, int i)
{
	if (lexer->s_quote == lexer->e_quote)
	{
		lexer->lex[i] = lexer->e_quote;
		lexer->s_quote = 0;
		lexer->e_quote = 0;
	}
	else
		lexer->lex[i] = c;
}

void	index_token(t_lst *token)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = token->head;
	while (tmp)
	{
		if (tmp->type == 'S')
		{
			tmp->i = i;
			i++;
		}
		else
		{
			i = 0;
			tmp->i = i;
		}
		tmp = tmp->next;
	}
}

void	type_token(t_lst *token)
{
	t_token	*tmp;

	tmp = token->head;
	while (tmp)
	{
		if ((ft_strcmp(tmp->token, PIPE)) == 0)
			tmp->type = 'P';
		else if ((ft_strcmp(tmp->token, O_REDIR)) == 0)
			tmp->type = 'O';
		else if ((ft_strcmp(tmp->token, I_REDIR)) == 0)
			tmp->type = 'I';
		else if ((ft_strcmp(tmp->token, A_REDIR)) == 0)
			tmp->type = 'A';
		else if ((ft_strcmp(tmp->token, HEREDOC)) == 0)
			tmp->type = 'H';
		else
			tmp->type = 'S';
		tmp = tmp->next;
	}
}

void	analyze_token(t_lst *token)
{
	type_token(token);
	index_token(token);
}

void	tokenizer(char *lex)
{
	int		i;
	int		st;
	int		ed;
	t_lst	*token;

	i = -1;
	st = -1;
	ed = -1;
	token = malloc(sizeof(t_lst));
	init_lst(token);
	while (lex[++i])
	{
		if (st == -1 && lex[i] != 's' && (lex[i] == 'c' || lex[i] == 'i'))
			st = i;
		if (st >= 0 &&
			(lex[i + 1] == 's' || lex[i + 1] == '\0' || lex[st] != lex[i + 1]))
		{
			ed = i;
			make_token(token, st, ed);
			st = -1;
			ed = -1;
		}
	}
	analyze_token(token);
	g_sh.token = token;
}

void	analyze_special_char(char *lex, int ret, int *i)
{
	if (ret == 2 || ret == 3)
	{
		lex[*i] = 'i';
		(*i)++;
		lex[*i] = 'i';
	}
	else if (ret > 0)
		lex[*i] = 'i';
}

void	lexer(char *cmd)
{
	int		i;
	int		ret;
	t_lexer	*lexer;

	i = -1;
	lexer = malloc(sizeof(t_lexer));
	init_lexer(lexer);
	while (cmd[++i])
	{
		if (ft_isalnum(cmd[i]))
			lexer->lex[i] = 'c';
		else if (lexer->s_quote == 0 &&
					((lexer->s_quote = ft_isquote(cmd[i])) >= 1))
			lexer->lex[i] = lexer->s_quote;
		else if (lexer->s_quote && ((lexer->e_quote = ft_isquote(cmd[i])) >= 1))
			analyze_quote_pair(lexer, cmd[i], i);
		else if (ft_isspace(cmd[i]))
			analyze_space(lexer, i);
		else if (lexer->s_quote == 0 && (ret = ft_isspec(cmd, i)))
			analyze_special_char(lexer->lex, ret, &i);
		else
			lexer->lex[i] = 'c';
	}
	if (lexer->s_quote != 0)
		lexer->err = 1;
}

void	set_terminal(void)
{
	tcgetattr(0, &g_sh.term);
	g_sh.term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &g_sh.term);
}

void	set_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	set_prompt(void)
{
	g_sh.cmd = readline(PROMPT);
	add_history(g_sh.cmd);
	rl_redisplay();
	lexer(g_sh.cmd);
	tokenizer(g_sh.lexer->lex);
	printf("cmd = %s\nlex = %s\n", g_sh.cmd, g_sh.lexer->lex);
	print_token(g_sh.token);
	if ((ft_strcmp(g_sh.cmd, "exit")) == 0)
		exit_shell(0);
	if (g_sh.lexer->err == 1)
		printf("quote err\n");
	free(g_sh.cmd);
	free_lexer(g_sh.lexer);
}

int		main(int ac, char **av, char **envp)
{
	int	ret;

	(void)av;
	ret = ac;
	g_sh.env = envp;
	set_terminal();
	while (ret)
	{
		set_signal();
		set_prompt();
	}
}
