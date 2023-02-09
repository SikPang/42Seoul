/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:21:39 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/09 19:43:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>		// open()
#include <unistd.h>		// close()
#include <stdlib.h>		// free()
#include "split/ft_split.h"
#include "utility/utility.h"
#include "main.h"

static void	child_process(t_arg *arg, t_fd *fd, int count, int last)
{
	char	*cmd_with_path;
	char	**cmd_args;
	int		i;

	if (count != last)
	{
		close(fd->file[WRITE]);
	 	close(fd->cur_pipe[READ]);
	}
	cmd_args = ft_split(arg->av[count + 2], ' ');
	if (cmd_args == _NULL)
		error_exit();
	i = 0;
	while (arg->paths[i] != 0)
	{
		cmd_with_path = ft_strjoin(arg->paths[i], cmd_args[0], 1);
		if (cmd_with_path == _NULL)
			error_exit();
		execve(cmd_with_path, cmd_args, arg->ev);
		free(cmd_with_path);
		++i;
	}
	perror_exit();
}

static void	pipex(t_arg *arg, t_fd *fd, int i)
{
	pid_t	pid;

	while (i < arg->ac - 1)
	{
		if (i < arg->ac - 2)
		{
			if (pipe(fd->cur_pipe) == -1)
				perror_exit();
		}
		dup_fds(fd, i - 2, arg->ac - 4);
		close_fds(fd, i - 2, arg->ac - 4);
		pid = fork();
		if (pid == -1)
			perror_exit();
		else if (pid == 0)
			child_process(arg, fd, i - 2, arg->ac - 4);
		fd->prev_pipe[0] = fd->cur_pipe[0];
		fd->prev_pipe[1] = fd->cur_pipe[1];
		++i;
	}
	close(STD_IN);
	close(STD_OUT);
	wait_all(arg->ac - 3);
}

int	main(int ac, char **av, char **ev)
{
	t_arg	arg;
	t_fd	fd;

	if (ac != 5)
		error_exit();
	arg.ac = ac;
	arg.av = av;
	arg.ev = ev;
	arg.paths = get_paths(ev);
	if (arg.paths == _NULL)
		error_exit();
	fd.file[READ] = open(av[1], O_RDONLY);
	fd.file[WRITE] = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd.file[READ] == -1 || fd.file[WRITE] == -1)
		perror_exit();
	pipex(&arg, &fd, 2);
	return (0);
}
