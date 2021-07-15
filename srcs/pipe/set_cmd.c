#include "../../includes/minishell.h"

void		combine_cmd(const char *cmd_1, char **path, t_all *all)
{
	int		i;
	char	**chunk;

	i = 0;
	if (!(ft_strlen(cmd_1)))
		print_error("cmd_1 is not exists");
	chunk = ft_split(cmd_1, ' ');
	while (*path)
	{
		all->pipe.cmd[i] = ft_strjoin(*path, chunk[0]);
		i++;
		path++;
	}
	all->pipe.cmd[i] = NULL;
	all->pipe.av = (char *const *)chunk;
	all->pipe.envp = NULL;
}

void		split_path(const char *cmd_1, char **path, t_all *all)
{
	int		i;
	char	**str;
	char	*tmp[100];

	i = -1;
	str = NULL;
	while (*path)
	{
		if ((**path == 'P') && (*(*path + 1) == 'A') && (*(*path + 2) == 'T')
				&& (*(*path + 3) == 'H'))
		{
			str = ft_split(*path, ':');
			break ;
		}
		path++;
	}
	while (str[++i])
	{
		tmp[i] = ft_strjoin(str[i], "/");
		free(str[i]);
	}
	tmp[i] = NULL;
	free(str);
	combine_cmd(cmd_1, tmp, all);
}
