/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkjaekwang <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:54:05 by parkjaekw         #+#    #+#             */
/*   Updated: 2021/07/13 19:42:03 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf g_sh;

void	print_system(void)
{
	printf("[lexical analysis]\n");
	printf("cmd = %s\nlex = %s\n", g_sh.cmd, g_sh.lexer->lex);
	printf("------------------\n");
	printf("[tokenizing]\n");
	print_token(g_sh.token);
	printf("------------------\n");
	printf("[parsing]\n");
	print_process(g_sh.process);
	printf("------------------\n");
}

void	print_token(t_lst *token)
{
	t_token	*temp;

	temp = token->head;
	while (temp)
	{
		printf("token = %s, type = %c, index = %d, st = %d, ed = %d, next = "
				"%p\n",
				temp->token,
				temp->type,
				temp->i,
				temp->st,
				temp->ed,
				temp->next);
		temp = temp->next;
	}
}

void	print_env(t_lst *env)
{
	t_env	*tmp;

	tmp = env->head;
	while (tmp)
	{
		printf("==============================\n");
		printf("key = %s\nvalue = %s\n", tmp->key, tmp->value);
		printf("==============================\n");
		tmp = tmp->next;
	}
}

void	print_syntax(t_lst *syntax)
{
	t_syntax	*tmp;

	tmp = syntax->head;
	while (tmp)
	{
		printf("cmd = %s, arg = %s\n", tmp->cmd, tmp->arg_line);
		tmp = tmp->next;
	}
}

void	print_process(t_lst *process)
{
	int			i;
	t_process	*tmp;

	i = 0;
	tmp = process->head;
	while (tmp)
	{
		printf("process no.%d\n", i);
		printf("next = %p\n", tmp->next);
		print_syntax(tmp->syntax);
		i++;
		tmp = tmp->next;
	}
}

