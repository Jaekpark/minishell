/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:40:26 by yeslee            #+#    #+#             */
/*   Updated: 2021/07/12 16:20:06 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_pid_not_zero(char **av, char **path, t_pipe *pipe)
{
	int		status;

	wait(&status);
	if (!(WIFEXITED(status)))
		exit(1);
	split_path(av[3], path, pipe);
	connect_out(av[4]);
	run_dup2(0, pipe);
	close_fd(3, pipe);
	run_execve(pipe);
}

static void	ft_pid_zero(char **av, char **path, t_pipe *pipe)
{
	int		pid;

	pipe(pipe->fd);
	pid = fork();
	if (pid > 0)
		ft_pid_not_zero(av, path, pipe);
	else if (pid == 0)
	{
		split_path(av[2], path, pipe);
		connect_in(av[1]);
		run_dup2(1, pipe);
		close_fd(3, pipe);
		run_execve(pipe);
	}
	else
		print_error("fork error");
}

int			main(int ac, char **av, char **path)
{
	pid_t	pid;
	t_pipe	pipe;
	int		status;

	if (ac != 5)
		print_error("The arguments are invalid");
	pid = fork();
	if (pid > 0)
	{
		wait(&status);
		if (!(WIFEXITED(status)))
			exit(1);
	}
	else if (pid == 0)
		ft_pid_zero(av, path, &pipe);
	else
		print_error("fork error");
	return (0);
}
