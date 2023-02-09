/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:54:56 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/09 20:18:05 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>		// open()
#include <unistd.h>		// close()
#include <stdlib.h>		// malloc(), free()
#include "get_next_line/get_next_line_bonus.h"
#include "utility/utility_bonus.h"
#include "main_bonus.h"

static void	set_read_file(t_arg *arg, t_fd *fd)
{
	char		*line;
	char		*temp;

	line = malloc(1);
	while (1)
	{
		free(line);
		line = get_next_line(0);
		if (line == _NULL)
			error_exit();
		if (ft_strcmp(line, arg->av[2]) == 0)
			break ;
		temp = line;
		while (*temp != '\0')
		{
			if (write(fd->file[READ], temp, 1) == -1)
				perror_exit();
			++temp;
		}
	}
	free(line);
}

void	here_doc(t_arg *arg, t_fd *fd)
{
	if (arg->ac != 6)
		error_exit();
	fd->file[READ] = open(".temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd->file[READ] == -1)
		perror_exit();
	arg->av[2] = ft_strjoin(arg->av[2], "\n", 0);
	if (arg->av[2] == _NULL)
		error_exit();
	set_read_file(arg, fd);
	close(fd->file[READ]);
	fd->file[READ] = open(".temp", O_RDONLY, 0644);
	fd->file[WRITE] = open(arg->av[arg->ac - 1],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd->file[READ] == -1 || fd->file[WRITE] == -1)
		perror_exit();
	pipex(arg, fd, 3, 2);
	unlink(".temp");
}