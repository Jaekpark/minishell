#include "../../includes/minishell.h"

/*
 *static void	remove_node(t_env **env, char *target)
 *{
 *    t_env	*node;
 *
 *    if (!(target))
 *        return ;
 *    node = *env;
 *    if (!(ft_strncmp(node->key, target, ft_strlen(node->key)))) // head
 *    {
 *        node->next->prev = NULL;
 *        return ;
 *    }
 *    while (node->next) // middle
 *    {
 *        if (!(ft_strncmp(node->key, target, ft_strlen(node->key))))
 *        {
 *            node->prev->next = node->next;
 *            node->next->prev = node->prev;
 *            return ;
 *        }
 *        node = node->next;
 *    }
 *    if (!(ft_strncmp(node->key, target, ft_strlen(node->key)))) // tail
 *        node->prev->next = NULL;
 *    return ;
 *}
 */

void		run_unset(int ac, char **av, char **path, t_all *all)
{
	if ((all->blt.up_flag == 1) || (ac == 2))
		return ;
	while (*path)
	{
		if (!(ft_strncmp(*path, av[2], 4)))
		{
			//	remove_node(all.env, target); // not execute
			printf(">> %s\n", *path);
		}
		path++;
	}
}
