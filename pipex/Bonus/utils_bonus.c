/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:57:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/09 18:59:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>		// close()
#include <sys/wait.h>	// wait(), pid_t
#include "split/ft_split_bonus.h"
#include "utility/utility_bonus.h"
#include "main_bonus.h"

void	wait_all(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (wait(0) == -1)
			perror_exit();
		++i;
	}
}

char	**get_paths(char **ev)
{
	char	**paths;
	int		i;

	i = 0;
	while (ev[i] != 0)
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
		{
			paths = ft_split(ev[i] + 5, ':');
			if (paths == _NULL)
				error_exit();
			return (paths);
		}
		++i;
	}
	return (_NULL);
}

void	close_fds(t_fd *fd, int i, int last)
{
	if (i == 0)
	{
		close(fd->file[READ]);
		close(fd->cur_pipe[WRITE]);
	}
	else if (i < last)
	{
		close(fd->prev_pipe[READ]);
		close(fd->cur_pipe[WRITE]);
		close(fd->prev_pipe[WRITE]);
	}
	else
	{
		close(fd->prev_pipe[READ]);
		close(fd->file[WRITE]);
		close(fd->prev_pipe[WRITE]);
	}
}

void	dup_fds(t_fd *fd, int i, int last)
{
	if (i == 0)
	{
		if (dup2(fd->file[READ], STD_IN) == -1
			|| dup2(fd->cur_pipe[WRITE], STD_OUT) == -1)
			perror_exit();
	}
	else if (i < last)
	{
		if (dup2(fd->prev_pipe[READ], STD_IN) == -1
			|| dup2(fd->cur_pipe[WRITE], STD_OUT) == -1)
			perror_exit();
	}
	else
	{
		if (dup2(fd->prev_pipe[READ], STD_IN) == -1
			|| dup2(fd->file[WRITE], STD_OUT) == -1)
			perror_exit();
	}
}
