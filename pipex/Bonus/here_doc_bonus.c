/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:19 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/08 22:46:02 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line_bonus.h"
#include "utility/utility_bonus.h"
#include "info_bonus.h"

static void	wait_here(t_here_doc *fd, int size)
{
	int	i;

	close(fd->pipe[READ]);
	close(fd->pipe[WRITE]);
	i = 0;
	while (i++ < size)
	{
		if (wait(0) == -1)
			perror_exit();
	}
}

static void	child_process(t_args *arg, t_here_doc *fd, int count)
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
}

static void	pipex(t_args *arg, t_here_doc *fd)
{
	int		count;
	pid_t	pid;

	count = 3;
	if (dup2(fd->input[TEMP], STD_IN) == -1
		|| dup2(fd->pipe[WRITE], STD_OUT) == -1)
		perror_exit();
	close(fd->input[TEMP]);
	while (count < arg->ac - 1)
	{
		if (count == arg->ac - 2)
		{
			if (dup2(fd->pipe[TEMP], STD_IN) == -1
				|| dup2(fd->input[WRITE], STD_OUT) == -1)
				perror_exit();
			close(fd->input[WRITE]);
		}
		pid = fork();
		if (pid == -1)
			perror_exit();
		else if (pid == 0)
			child_process(arg, fd, count);
		++count;
	}
}

static void	get_line(t_args	*arg, t_here_doc *hd)
{
	char		*line;
	char		*temp;

	line = malloc(1);
	while (1)
	{
		free(line);
		line = get_next_line(0);
		if (line == NULL)
			error_exit();
		if (ft_strcmp(line, arg->av[2]) == 0)
			break ;
		temp = line;
		while (*temp != '\0')
		{
			if (write(hd->input[TEMP], temp, 1) == -1)
				perror_exit();
			++temp;
		}
	}
	free(line);
}

void	here_doc(t_args	*arg)
{
	t_here_doc	hd;

	if (arg->ac != 6)
		error_exit();
	hd.input[TEMP] = open(".temp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (hd.input[TEMP] == -1)
		perror_exit();
	if (pipe(hd.pipe) == -1)
		perror_exit();
	arg->av[2] = ft_rstrjoin(arg->av[2], "\n");
	if (arg->av[2] == NULL)
		error_exit();
	get_line(arg, &hd);
	close(hd.input[TEMP]);
	hd.input[TEMP] = open(".temp", O_RDONLY, 0666);
	hd.input[WRITE] = open(arg->av[arg->ac - 1],
			O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (hd.input[TEMP] == -1 || hd.input[WRITE] == -1)
		perror_exit();
	pipex(arg, &hd);
	wait_here(&hd, 2);
	unlink(".temp");
}
