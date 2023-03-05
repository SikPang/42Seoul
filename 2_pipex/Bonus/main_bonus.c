/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:21:39 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/09 21:13:51 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>		// open()
#include <unistd.h>		// close()
#include <stdlib.h>		// free()
#include "split/ft_split_bonus.h"
#include "utility/utility_bonus.h"
#include "main_bonus.h"

void	child_process(t_arg *arg, t_fd *fd, int index, int cmd_size)
{
	char	*cmd_with_path;
	char	**cmd_args;
	int		i;

	if (index != cmd_size - 1)
	{
		close(fd->file[WRITE]);
		close(fd->cur_pipe[READ]);
	}
	cmd_args = ft_split(arg->av[index], ' ');
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

void	pipex(t_arg *arg, t_fd *fd, int index, int cmd_size)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < cmd_size)
	{
		if (i < cmd_size - 1)
		{
			if (pipe(fd->cur_pipe) == -1)
				perror_exit();
		}
		dup_fds(fd, i, cmd_size);
		close_fds(fd, i, cmd_size);
		pid = fork();
		if (pid == -1)
			perror_exit();
		else if (pid == 0)
			child_process(arg, fd, i + index, i + cmd_size);
		fd->prev_pipe[0] = fd->cur_pipe[0];
		fd->prev_pipe[1] = fd->cur_pipe[1];
		++i;
	}
	close(STD_IN);
	close(STD_OUT);
	wait_all(cmd_size);
}

int	main(int ac, char **av, char **ev)
{
	t_arg	arg;
	t_fd	fd;

	if (ac < 5)
		error_exit();
	arg.ac = ac;
	arg.av = av;
	arg.ev = ev;
	arg.paths = get_paths(ev);
	if (arg.paths == _NULL)
		error_exit();
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		here_doc(&arg, &fd);
		return (0);
	}
	fd.file[READ] = open(av[1], O_RDONLY);
	fd.file[WRITE] = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd.file[READ] == -1 || fd.file[WRITE] == -1)
		perror_exit();
	pipex(&arg, &fd, 2, ac - 3);
	return (0);
}
