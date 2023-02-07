/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:36:21 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/07 22:41:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utility/utility_bonus.h"
#include "info_bonus.h"

void	dup_fds(t_fds *fd, t_args *arg, int count)
{
	if (count == 2)
	{
		if (dup2(fd->input[READ], STD_IN) == -1
			|| dup2(fd->pipe[count - 2][WRITE], STD_OUT) == -1)
			perror_exit();
	}
	else if (count < arg->ac - 2)
	{
		if (dup2(fd->pipe[count - 3][READ], STD_IN) == -1
			|| dup2(fd->pipe[count - 2][WRITE], STD_OUT) == -1)
			perror_exit();
	}
	else
	{
		if (dup2(fd->pipe[fd->pipe_size - 1][READ], STD_IN) == -1
			|| dup2(fd->input[WRITE], STD_OUT) == -1)
			perror_exit();
	}
}

void	close_fds(t_fds *fd, t_args *arg, int count)
{
	int	i;

	i = 0;
	if (count == 2)
	{
		while (i < fd->pipe_size)
		{
			close(fd->pipe[i][READ]);
			if (i != count - 2)
				close(fd->pipe[i][WRITE]);
			++i;
		}
	}
	else if (count < arg->ac - 2)
	{
		while (i < fd->pipe_size)
		{
			if (i != count - 3)
				close(fd->pipe[i][READ]);
			if (i != count - 2)
				close(fd->pipe[i][WRITE]);
			++i;
		}
	}
	else
	{
		while (i < fd->pipe_size)
		{
			if (i != fd->pipe_size - 1)
				close(fd->pipe[i][READ]);
			close(fd->pipe[i][WRITE]);
			++i;
		}
	}
}
