#include "../../includes/minishell.h"

int		double_strlen(const char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	run_execve(t_all *all)
{
	int	i;

	i = double_strlen(all->pipe.cmd);
	while (--i >= 0)
	{
		execve(all->pipe.cmd[i], all->pipe.av, all->pipe.envp);
	}
	print_error("execve error");
}
