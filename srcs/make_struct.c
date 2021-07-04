/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:37:36 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/04 15:28:23 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_conf g_sh;

void	make_div(t_lst *lst, int st, int ed)
{	
	t_div	*tmp;
	t_div	*node;

	node = malloc(sizeof(t_token));
	node->st = st;
	node->ed = ed;
	node->next = NULL;
	node->prev = NULL;
	if (lst->head == NULL && lst->tail == NULL)
	{
		lst->head = node;
		lst->tail = node;
	}
	else if (lst->head != NULL && lst->tail != NULL)
	{
		tmp = lst->tail;
		node->prev = tmp;
		tmp->next = node;
		lst->tail = node;
	}
}

void	make_token(t_lst *lst, int st, int ed)
{
	t_token	*tmp;
	t_token	*node;

	node = malloc(sizeof(t_token));
	node->token = ft_strrdup(g_sh.cmd, st, ed);
	node->next = NULL;
	node->prev = NULL;
	if (lst->head == NULL && lst->tail == NULL)
	{
		lst->head = node;
		lst->tail = node;
	}
	else if (lst->head != NULL && lst->tail != NULL)
	{
		tmp = lst->tail;
		node->prev = tmp;
		tmp->next = node;
		lst->tail = node;
	}
}
