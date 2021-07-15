#include "../../includes/minishell.h"

void	run_cd(char **av, char **path, t_all *all)
{
	int		i;
	int		ret;
	char	**dir;
	char	buf[256];

	if (all->blt.up_flag == 1)
		return ;
	else if (!(av[2])) // $HOME
	{
		i = -1;
		while (path[++i])
		{
			if (!(ft_strncmp(path[i], "HOME", 4)))
			{
				dir = ft_split(path[i], '=');
				printf("%s\n", dir[1]);
			}
		}
	}
	else
	{
		ret = chdir(av[2]);
		if (ret == -1)
			printf("%s\n", strerror(errno));
		else if (!(ret))
		{
			printf("chdir >> %d\n", ret);
			getcwd(buf, 0);
			printf("path >> %s\n", buf); // will put pwd's value by ylee >> error
		}
	}
}
