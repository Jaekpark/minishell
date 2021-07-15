#include "../../includes/minishell.h"

void	run_env(char **path)
{
	int	e_flag;

	e_flag = 0;
	while (*path)
	{
		if (e_flag == 1)
			printf("declare -x %s\n", *path);
		else
			printf("%s\n", *path);
		path++;
	}
}
