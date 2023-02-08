/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:36:21 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/08 21:03:21 by kwsong           ###   ########.fr       */
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
		close(fd->input[READ]);
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
		close(fd->input[WRITE]);
	}
}

void	close_fds(t_fds *fd, t_args *arg, int count)
{
	int	i;

	i = 0;
	while (i < fd->pipe_size)
	{
		if ((count != 2 && count < arg->ac - 2 && i != count - 3)
			|| (count == arg->ac - 2 && i != fd->pipe_size - 1)
			|| count == 2)
			close(fd->pipe[i][READ]);
		if ((count != 2 && count < arg->ac - 2 && i != count - 2)
			|| (count == 2 && i != count - 2)
			|| count == arg->ac - 2)
			close(fd->pipe[i][WRITE]);
		++i;
	}
}
