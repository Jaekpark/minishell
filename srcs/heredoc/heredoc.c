#include "../includes/pipe.h"

void		hdoc_init(t_all *all)
{
	all->hdoc.delimiter = NULL;
	all->hdoc.arg = NULL;
}

static void	set_first_fork(av, path, &all);
{
	int		pid;
	char	*buf;
	char	*dlmt;

	pipe(all->pipe.fd[2]);
	pid = fork;
	if (pid > 0) // cmd
		printf("it is for minishell");
	else if (pid == 0) // heredoc
	{
		buf = NULL;
		write(1, ">", 1);
		run_dup2(fd[0], 0);
		close_fd(1);
		while (get_next_line(fd[0], &buf) > 0)
		{
			if (!(ft_strncmp(buf, "\n", ft_strlen(buf))))
				write(fd[1])
		}	
	}
	else
		printf("fork error\n");
}

int			main(int ac, char **av, char **path)
{
	int		status;
	pid_t	pid;
	t_all	all;

	if (ac != 4)
		printf("invalid ac\n");
	pid = fork();
	if (pid > 0)
	{
		wait(&status);
		if (!(WIFEXITED(status)))
			exit(1);
	}
	else if (pid == 0)
		set_first_fork(av, path, &all);
	else
		write(2, "fork error\n", 11);
	return (0);
}
