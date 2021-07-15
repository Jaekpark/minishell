/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjaekwang <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:26:58 by parkjaekw         #+#    #+#             */
/*   Updated: 2021/07/15 20:16:00 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf g_sh;

void	set_prompt(void)
{
	g_sh.cmd = readline(PROMPT);
	if (ft_strcmp(g_sh.cmd, "exit") == 0)
		exit_shell(0);
	add_history(g_sh.cmd);
	rl_redisplay();
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

void	set_process(void)
{
	t_token	*tmp;

	tmp = NULL;
	lexer(g_sh.cmd);
	if (g_sh.lexer->err == 1)
		exit_shell(0);
	tokenizer(g_sh.lexer->lex);
	tmp = g_sh.token->head;
	while (tmp)
		tmp = parser(g_sh.process, tmp);
	if (tmp != NULL)
		parser(g_sh.process, tmp);
	print_system();
}

void	set_env(char **envp)
{
	int		i;
	char	**tmp;
	t_lst	*env;

	i = -1;
	tmp = NULL;
	env = malloc(sizeof(t_lst));
	init_lst(env);
	g_sh.envp = envp;
	while (envp[++i])
	{
		tmp = ft_split_env(envp[i]);
		make_env(env, tmp[0], tmp[1]);
		ft_free_double((void **)tmp);
	}
	g_sh.env = env;
}
