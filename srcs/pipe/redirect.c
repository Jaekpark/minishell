#include "../../includes/minishell.h"

void	connect_in(char *file)
{
	int	fd;
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error("The file is not open");
	if (dup2(fd, STDIN) == -1)
		print_error("dup2 error");
	if (close(fd) == -1)
		print_error("close error");
}

void	connect_out(char *file)
{
	int	fd;

	if ((fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644)) < 0)
		print_error("The file is not open");
	if (dup2(fd, STDOUT) == -1)
		print_error("dup2 error");
	if (close(fd) == -1)
		print_error("close error");
}

void	run_dup2(int std_fd, int *fd)
{
	if (std_fd == 0)
	{
		if (dup2(fd[0], std_fd) == -1)
			print_error("dup2 error");
	}
	else if (std_fd == 1)
	{
		if (dup2(fd[1], std_fd) == -1)
			print_error("dup2 error");
	}
}

void	close_fd(int flag, int *fd) // have to change flags
{
	if (flag == 1)
	{
		if (close(fd[0]) == -1)
			print_error("close(fd[0])");
	}
	else if (flag == 2)
	{
		if (close(fd[1]) == -1)
			print_error("close(fd[1]) error");
	}
	else if (flag == 3)
	{
		if (close(fd[0]) == -1)
			print_error("close(fd[0]) error");
		if (close(fd[1]) == -1)
			print_error("close(fd[1]) error");
	}
}
