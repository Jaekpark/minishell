/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:15:00 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/03 16:07:46 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_conf g_sh;

void	init_lexer(t_lexer *lexer)
{
	lexer->lex = ft_strdup(g_sh.cmd);
	ft_memset(lexer->lex, 0, ft_strlen(lexer->lex));
	lexer->is_quote = 0;
	lexer->s_quote = 0;
	lexer->e_quote = 0;
	lexer->err = 0;
	g_sh.lexer = lexer;
}

void	init_flag(t_flag *flag)
{
	flag->st = 0;
	flag->ed = 0;
	flag->quote = 0;
	flag->d_quote = 0;
}

void	init_lst(t_lst *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}
