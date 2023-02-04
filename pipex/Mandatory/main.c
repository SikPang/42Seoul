/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/04 21:21:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "utility/utility.h"
#include "info.h"

void	put_str(char *str)
{
	int	i;

	i = 0;
	write(2, "  ", 2);
	while(str[i] != 0)
	{
		write(2, &str[i], 1);
		++i;
	}
	write(2, " ", 1);
}

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
		put_str(find_str);
		execve(find_str, cmd_args, arg->ev);
		write(2, "_ failed\n", 9);
		free(find_str);
		++i;
	}
	write(2, "execve failed\n", 14);
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

	count = 2;
	dup2(fd->input[READ], STD_IN);	// stdin -> input_file
	dup2(fd->pipe[WRITE], STD_OUT);	// stdout -> pipe
	close(fd->pipe[WRITE]);
	while (count < arg->ac - 1)
	{
		write(2, "while...\n", 9);
		if (count > 2)
		{
			dup2(fd->pipe[READ], STD_IN);		// stdin -> pipe
			dup2(fd->input[WRITE], STD_OUT);	// stdout -> output_file
		}
		pid = fork();
		if (pid == 0)
			child_process(arg, fd, count);
		else
		{
			write(2, " waiting...\n", 12);
			wait(0);
			write(2, "\n done! wait\n", 13);
		}
		++count;
	}
	write(2, "done! while\n", 12);
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