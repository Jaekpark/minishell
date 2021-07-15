/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:37:36 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/15 19:56:52 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf	g_sh;

void			syntax_to_lst(t_lst *lst, t_syntax *node)
{
	t_syntax	*tmp;

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

void			make_syntax(t_lst *lst, char *cmd, char *arg)
{
	t_syntax	*node;

	node = malloc(sizeof(t_syntax));
	if (cmd != NULL)
		node->cmd = ft_strdup(cmd);
	else
		node->cmd = NULL;
	if (arg != NULL)
		node->arg_line = ft_strdup(arg);
	else
		node->arg_line = NULL;
	node->arg_word = NULL;
	node->next = NULL;
	node->prev = NULL;
	syntax_to_lst(lst, node);
	if (cmd)
		free(cmd);
	if (arg)
		free(arg);
}

void			save_process(t_lst *lst, t_lst *syntax)
{
	t_process	*tmp;
	t_process	*node;

	node = malloc(sizeof(t_process));
	node->syntax = syntax;
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

void			make_token(t_lst *lst, int st, int ed)
{
	t_token	*tmp;
	t_token	*node;

	node = malloc(sizeof(t_token));
	node->token = ft_strrdup(g_sh.cmd, st, ed);
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

void			make_env(t_lst *lst, char *key, char *value)
{
	t_env	*tmp;
	t_env	*node;

	node = malloc(sizeof(t_env));
	node->next = NULL;
	node->prev = NULL;
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
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
