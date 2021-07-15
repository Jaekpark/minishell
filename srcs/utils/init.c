/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:15:00 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/15 19:59:53 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf g_sh;

void	init_config(void)
{
	g_sh.lexer = malloc(sizeof(t_lexer));
	g_sh.process = malloc(sizeof(t_lst));
	g_sh.token = malloc(sizeof(t_lst));
	init_lst(g_sh.process);
	init_lst(g_sh.token);
	init_lexer(g_sh.lexer);
}

void	init_tool(t_tool *tool)
{
	tool->i = -1;
	tool->is_quote = 0;
	tool->st = -1;
	tool->ed = -1;
}

void	init_lexer(t_lexer *lexer)
{
	lexer->is_quote = 0;
	lexer->s_quote = 0;
	lexer->e_quote = 0;
	lexer->err = 0;
	g_sh.lexer = lexer;
}

void	init_lst(t_lst *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}
