/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/08 18:08:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "utility/utility_bonus.h"
#include "info_bonus.h"

static void	child_process(t_args *arg, t_fds *fd, int count)
{
	char	*find_str;
	char	**cmd_args;
	int		i;

	i = 0;
	close_fds(fd, arg, count);
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
	while (count < arg->ac - 1)
	{
		dup_fds(fd, arg, count);
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

static void	init_pipe(t_fds *fd)
{
	int	i;

	fd->pipe = (int **)malloc((fd->pipe_size) * sizeof(int *));
	if (fd->pipe == NULL)
		error_exit();
	i = 0;
	while (i < fd->pipe_size)
	{
		fd->pipe[i] = (int *)malloc(2 * sizeof(int));
		if (fd->pipe[i] == NULL)
			error_exit();
		if (pipe(fd->pipe[i]) == -1)
			perror_exit();
		++i;
	}
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

	if (ac < 5)
		error_exit();
	arg.ac = ac;
	arg.av = av;
	arg.ev = ev;
	arg.paths = get_paths(ev);
	if (arg.paths == NULL)
		error_exit();
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		here_doc(&arg);
		while (1);
		return (0);
	}
	fd.pipe_size = ac - 4;
	fd.input[READ] = open(av[1], O_RDONLY);
	fd.input[WRITE] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd.input[READ] == -1 || fd.input[WRITE] == -1)
		perror_exit();
	init_pipe(&fd);
	pipex(&arg, &fd);
	return (0);
}
