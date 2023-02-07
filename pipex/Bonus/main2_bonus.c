/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:36:21 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/07 19:41:11 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utility/utility_bonus.h"
#include "info_bonus.h"
#include <stdio.h>
void	dup_fds(t_fds *fd, t_args *arg, int count)
{
	if (count == 2)
	{
		// printf("%d : read file\n", count);
		// printf("%d : write pipe = %d\n", count, count - 2);
		if (dup2(fd->input[READ], STD_IN) == -1
			|| dup2(fd->pipe[count - 2][WRITE], STD_OUT) == -1)
			perror_exit();
	}
	else if (count == arg->ac - 2)
	{
		// printf("%d : read pipe = %d\n", count, fd->pipe_size - 1);
		// printf("%d : write file\n", count);
		if (dup2(fd->pipe[fd->pipe_size - 1][READ], STD_IN) == -1
			|| dup2(fd->input[WRITE], STD_OUT) == -1)
			perror_exit();
	}
	else
	{
		// printf("%d : read pipe = %d\n", count, count - 3);
		// printf("%d : write pipe = %d\n", count, count - 2);
		if (dup2(fd->pipe[count - 3][READ], STD_IN) == -1
			|| dup2(fd->pipe[count - 2][WRITE], STD_OUT) == -1)
			perror_exit();
	}
}

void	close_fd(t_fds *fd, t_args *arg, int count)
{
	if (count == 2)
	{
		//printf("  %d : close pipe [read] = %d\n", count, count - 2);
		close(fd->pipe[count - 2][READ]);
	}
	else if (count == arg->ac - 2)
	{
		//printf("  %d : close pipe [write] = %d\n", count, fd->pipe_size - 1);
		close(fd->pipe[fd->pipe_size - 1][WRITE]);
	}
	else
	{
		//printf("  %d : close pipe [write] = %d\n", count, count - 3);
		//printf("  %d : close pipe [read] = %d\n", count, count - 2);
		close(fd->pipe[count - 3][WRITE]);
		close(fd->pipe[count - 2][READ]);
	}
}
