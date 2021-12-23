/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:17:44 by jaekpark          #+#    #+#             */
/*   Updated: 2021/12/23 23:32:30 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf g_sh;

static void	analyze_space(t_lexer *lexer, int i)
{
	if (!lexer)
		return ;
	if (lexer->s_quote > TRUE)
		lexer->lex[i] = 'c';
	else if (lexer->s_quote == FALSE)
		lexer->lex[i] = 's';
}

static void	analyze_quote(t_lexer *lexer, char c, int i)
{
	(void)c;
	if (lexer->s_quote == lexer->e_quote)
	{
		lexer->lex[i] = lexer->e_quote;
		lexer->s_quote = 0;
		lexer->e_quote = 0;
	}
	else
		lexer->lex[i] = 'c';
}

static void	analyze_operator(char *lex, int ret, int *i)
{
	if (ret == 2 || ret == 3)
	{
		lex[*i] = 'i';
		(*i)++;
		lex[*i] = 'i';
	}
	else if (ret > 0)
		lex[*i] = 'i';
	else
		return ;
}

void		lexer(char *cmd)
{
	int		i;
	int		ret;
	t_lexer *lexer;

	lexer = g_sh.lexer;
	lexer->lex = ft_strdup(cmd);
	ft_memset(lexer->lex, 0, ft_strlen(cmd));
	i = -1;
	while (cmd[++i])
	{
		if (ft_isalnum(cmd[i]))
			lexer->lex[i] = 'c';
		else if (lexer->s_quote == 0 &&
					((lexer->s_quote = ft_isquote(cmd[i])) >= 1))
			lexer->lex[i] = lexer->s_quote;
		else if (lexer->s_quote && ((lexer->e_quote = ft_isquote(cmd[i])) >= 1))
			analyze_quote(lexer, cmd[i], i);
		else if (ft_isspace(cmd[i]))
			analyze_space(lexer, i);
		else if (lexer->s_quote == 0 && (ret = ft_isspec(cmd, i)))
			analyze_operator(lexer->lex, ret, &i);
		else
			lexer->lex[i] = 'c';
	}
	if (lexer->s_quote != 0)
		lexer->err = 1;
}
