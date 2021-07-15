#include "../../includes/minishell.h"

/*
 *static void	add_node_back(t_env **env, t_env *new) // **env == existing node
 *{
 *    t_env *node;
 *
 *    if (!(new) || !(*env))
 *        return ;
 *    node = *env;
 *    while (node->next)
 *        node = node->next;
 *    node->next = new;
 *    new->prev = node;
 *    new->next = NULL;
 *}
 */

void		run_export(char **av, char **path, t_all *all)
{
	int		e_flag;
	char	**in_tmp;
	char	**ex_tmp;

	if (all->blt.up_flag == 1)
		return ;
	if (!(av[2]))
	{
		e_flag = 1;
		while (*path) // call->env func
		{
			printf("declare -x %s\n", *path);
			path++;
		}
	}
	else // lst_addback
	{
		in_tmp = ft_split(av[2], '=');
		while (*path)
		{
			ex_tmp = ft_split(*path, '=');
			all->env.key = ex_tmp[0];
			all->env.value = ex_tmp[1];
			if (!(ft_strncmp(*path, in_tmp[0], 4))) // key is already exists
			{
				all->env.value = in_tmp[1];
				return ;
			}
			path++;
		}
		//	add_node_back(all->env, new); // add new key=value // not execute
	}
}
