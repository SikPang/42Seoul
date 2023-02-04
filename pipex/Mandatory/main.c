/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/04 19:34:03 by kwsong           ###   ########.fr       */
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
	cmd_args = ft_split(arg->av[count], ' ');
	while (arg->paths[i] != 0)
	{
		find_str = ft_strjoin(arg->paths[i], arg->av[count]);
		execve(find_str, cmd_args, arg->ev);
		free(find_str);
		++i;
	}
	i = 0;
	while (cmd_args[i] != 0)
	{
		free(cmd_args[i]);
		++i;
	}
	free(cmd_args);
}

static void	pipex(t_args *arg, t_fds *fd)
{
	int		count;
	pid_t 	pid;

	count = 1;
	dup2(fd->pipe[WRITE], STD_OUT);
	dup2(fd->pipe[READ], STD_IN);
	while (count < arg->ac - 2)
	{
		if (count == arg->ac - 3)
			dup2(fd->pipe[WRITE], fd->input[WRITE]);
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

	while (*ev != 0)
	{
		if (ft_strncmp(*ev, "PATH=", 5) == 0)
		{
			paths = ft_split((*ev) + 5, ':');
			return (paths);
		}
		++ev;
	}
	return (0);
}

int main(int ac, char **av, char **ev)
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