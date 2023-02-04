/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/04 17:03:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "utility/utility.h"
#include "info.h"

static void	pipex(t_args *arg, t_fds *fd)
{
	int		count;
	char	buffer[BUFFER_SIZE];

	count = 1;
	//dup2(pipe_fds[OUT], STD_OUT);
	while (1)
	{
		if (count == arg->ac - 1)
			break ;
		
		pid_t pid = fork();
		
		if (pid == 0)
		{
			char *find_str = ft_strjoin(*(arg->paths), arg->av[count]);
			while (execve(find_str, 0, arg->ev) == -1)
			{
				write(2, find_str, ft_strlen(find_str));
				write(2, " cmd failed\n", 12);
				free(find_str);
				++(arg->paths);
				find_str = ft_strjoin(*(arg->paths), arg->av[count]);
			}
			write(2, find_str, ft_strlen(find_str));
			write(2, " cmd success!\n", 14);
			free(find_str);
		}
		else
		{
			write(2, "wait...\n", 8);
			wait(0);
			write(2, "wait done!\n", 11);

			write(2, "read...\n", 8);
			read(fd->pipe[IN], buffer, BUFFER_SIZE);
			write(2, "read done!\n", 11);
			
			//write(fd[1], buffer, BUFFER_SIZE);
			//write(2, "write done!\n\n", 13);
		}
		++count;
	}
}

static char	**get_paths(char **ev)
{
	char	**paths;

	paths = 0;
	while (*ev != 0)
	{
		if (ft_strncmp(*ev, "PATH=", 5) == 0)
		{
			paths = ft_split((*ev) + 5, ':');
			return (paths);
		}
		++ev;
	}
	return (0);
}

int main(int ac, char **av, char **ev)
{
	t_args	arg;
	t_fds	fd;

	if (ac != 5)
		error_exit();
	fd.input[IN] = open(av[1], O_RDONLY);
	fd.input[OUT] = open(av[ac - 1], O_WRONLY | O_CREAT);
	if (fd.input[IN] == -1 || fd.input[OUT] == -1)
		error_exit();
	arg.paths = get_paths(ev);
	if (arg.paths == NULL)
		error_exit();
	if (pipe(fd.pipe) == -1)
		error_exit();
	arg.ac = ac;
	arg.av = av;
	arg.ev = ev;
	pipex(&arg, &fd);
    return (0);
}