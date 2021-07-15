/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:35:59 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/15 19:48:54 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf	g_sh;

void			free_conf(t_conf *conf)
{
	if (!conf)
		return ;
	if (conf->cmd)
		free(conf->cmd);
	if (conf->lexer)
		free_lexer(conf->lexer);
	if (conf->token)
		free_token(conf->token);
	if (conf->process)
		free_process(conf->process);
}

void			free_env(t_lst *env)
{
	t_env	*tmp;

	if (!env)
		return ;
	tmp = env->head;
	while (tmp)
	{
		if (tmp->key != NULL)
			free(tmp->key);
		if (tmp->value != NULL)
			free(tmp->value);
		tmp = tmp->next;
	}
	free(env);
}

void			free_lexer(t_lexer *lexer)
{
	if (!lexer)
		return ;
	else if (lexer->lex != NULL)
		free(lexer->lex);
	free(lexer);
}

void			free_token(t_lst *token)
{
	t_token	*node;
	t_token	*tmp;

	if (!token)
		return ;
	tmp = token->tail;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->prev;
		if (node)
		{
			if (node->token)
				free(node->token);
			free(node);
		}
	}
	free(token);
}

void			free_syntax(t_lst *syntax)
{
	t_syntax	*node;
	t_syntax	*tmp;

	if (!syntax)
		return ;
	tmp = syntax->tail;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->prev;
		if (node->arg_line != NULL)
			free(node->arg_line);
		if (node->arg_word != NULL)
			ft_free_double((void **)node->arg_word);
		if (node->cmd != NULL)
			free(node->cmd);
		free(node);
	}
	free(syntax);
}

void			free_process(t_lst *process)
{
	t_process	*node;
	t_process	*tmp;

	if (!process)
		return ;
	tmp = process->tail;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->prev;
		if (node->syntax != NULL)
			free_syntax(node->syntax);
		free(node);
	}
	free(process);
}
