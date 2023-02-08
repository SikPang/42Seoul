/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/08 21:17:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "utility/utility.h"
#include "info.h"

static void	child_process(t_args *arg, t_fds *fd, int count)
{
	char	*find_str;
	char	**cmd_args;
	int		i;

	i = 0;
	if (count < arg->ac - 2)
		close(fd->pipe[READ]);
	else
		close(fd->pipe[WRITE]);
	cmd_args = ft_split(arg->av[count], ' ');
	if (cmd_args == NULL)
		error_exit();
	while (arg->paths[i] != 0)
	{
		find_str = ft_strjoin(arg->paths[i], cmd_args[0]);
		if (find_str == NULL)
			error_exit();
		execve(find_str, cmd_args, arg->ev);
		free(find_str);
		++i;
	}
	perror_exit();
}

static void	pipex(t_args *arg, t_fds *fd)
{
	int		count;
	pid_t	pid;

	count = 2;
	if (dup2(fd->input[READ], STD_IN) == -1
		|| dup2(fd->pipe[WRITE], STD_OUT) == -1)
		perror_exit();
	close(fd->input[READ]);
	while (count < arg->ac - 1)
	{
		if (count == arg->ac - 2)
		{
			if (dup2(fd->pipe[READ], STD_IN) == -1
				|| dup2(fd->input[WRITE], STD_OUT) == -1)
				perror_exit();
			close(fd->input[WRITE]);
		}
		pid = fork();
		if (pid == -1)
			perror_exit();
		else if (pid == 0)
			child_process(arg, fd, count);
		++count;
	}
	if (wait(0) == -1)
		perror_exit();
}

static char	**get_paths(char **ev)
{
	char	**paths;
	int		i;

	i = 0;
	while (ev[i] != 0)
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
		{
			paths = ft_split(ev[i] + 5, ':');
			if (paths == NULL)
				error_exit();
			return (paths);
		}
		++i;
	}
	return (NULL);
}

int	main(int ac, char **av, char **ev)
{
	t_args	arg;
	t_fds	fd;

	if (ac != 5)
		error_exit();
	arg.ac = ac;
	arg.av = av;
	arg.ev = ev;
	fd.input[READ] = open(av[1], O_RDONLY);
	fd.input[WRITE] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd.input[READ] == -1 || fd.input[WRITE] == -1)
		perror_exit();
	arg.paths = get_paths(ev);
	if (arg.paths == NULL)
		error_exit();
	if (pipe(fd.pipe) == -1)
		perror_exit();
	pipex(&arg, &fd);
	return (0);
}
