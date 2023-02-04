/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/04 21:54:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "utility/utility.h"
#include "info.h"

static void	child_process(t_args *arg, t_fds *fd, int count)
{
	char	*find_str;
	char	**cmd_args;
	int		i;

	i = 0;
	if (count == 2)
		close(fd->pipe[READ]);
	else
		close(fd->pipe[WRITE]);
	cmd_args = ft_split(arg->av[count], ' ');
	while (arg->paths[i] != 0)
	{
		find_str = ft_strjoin(arg->paths[i], arg->av[count]);
		execve(find_str, cmd_args, arg->ev);
		free(find_str);
		++i;
	}
	error_exit();
}

static void	pipex(t_args *arg, t_fds *fd)
{
	int		count;
	pid_t	pid;

	count = 2;
	dup2(fd->input[READ], STD_IN);
	dup2(fd->pipe[WRITE], STD_OUT);
	close(fd->pipe[WRITE]);
	while (count < arg->ac - 1)
	{
		if (count > 2)
		{
			dup2(fd->pipe[READ], STD_IN);
			dup2(fd->input[WRITE], STD_OUT);
		}
		pid = fork();
		if (pid == 0)
			child_process(arg, fd, count);
		else
			wait(0);
		++count;
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
			return (paths);
		}
		++i;
	}
	return (0);
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
	fd.input[WRITE] = open(av[ac - 1], O_WRONLY | O_CREAT);
	if (fd.input[READ] == -1 || fd.input[WRITE] == -1)
		error_exit();
	arg.paths = get_paths(ev);
	if (arg.paths == NULL)
		error_exit();
	if (pipe(fd.pipe) == -1)
		error_exit();
	pipex(&arg, &fd);
	return (0);
}
