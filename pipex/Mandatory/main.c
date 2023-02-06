/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/06 19:26:20 by kwsong           ###   ########.fr       */
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

// void	put_str(char *str)
// {
// 	int	i;

// 	i = 0;
// 	write(2, " ", 1);
// 	while(str[i] != 0)
// 	{
// 		write(2, &str[i], 1);
// 		++i;
// 	}
// 	write(2, "\n", 1);
// }

// void	put_2d_str(char **str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	write(2, "=== 2d str ===\n", 15);
// 	while(str[i] != 0)
// 	{
// 		j = 0;
// 		write(2, "  ", 2);
// 		while(str[i][j] != 0)
// 		{
// 			write(2, &str[i][j], 1);
// 			++j;
// 		}
// 		write(2, "\n", 1);
// 		++i;
// 	}
// 	write(2, "==============\n", 15);
// }

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
	error_exit();
}

static void	pipex(t_args *arg, t_fds *fd)
{
	int		count;
	pid_t	pid;
	int		wait_val;

	count = 2;
	if (dup2(fd->input[READ], STD_IN) == -1
		|| dup2(fd->pipe[WRITE], STD_OUT) == -1)
		perror_exit();
	while (count < arg->ac - 1)
	{
		if (count == arg->ac - 2)
		{
			if (dup2(fd->pipe[READ], STD_IN) == -1
				|| dup2(fd->input[WRITE], STD_OUT) == -1)
				perror_exit();
		}
		pid = fork();
		if (pid == -1)
			perror_exit();
		else if (pid == 0)
			child_process(arg, fd, count);
		++count;
	}
	if (wait(&wait_val) == -1)
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
	if (access(av[1], R_OK) == -1)
		perror_exit();
	fd.input[READ] = open(av[1], O_RDONLY);
	fd.input[WRITE] = open(av[ac - 1], O_WRONLY | O_CREAT, 0666);
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
