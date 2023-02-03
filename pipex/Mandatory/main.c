/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/03 22:45:53 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "utility/utility.h"

#define BUFFER_SIZE 100

#include <stdio.h>

// arg parsing

static char	**get_paths(char **ev)
{
	char	**paths;

	paths = 0;
	while (*ev != 0)
	{
		if (ft_strncmp(*ev, "PATH=", 5) == 0)
		{
			paths = ft_split((*ev) + 5, ':');
			break ;
		}
		++ev;
	}
	return (paths);
}

int main(int ac, char **av, char **ev)
{
	char	**paths;
	char	buffer[BUFFER_SIZE];
	int		fds[2];
	int		count;

	paths = get_paths(ev);
	count = 1;
	pipe(fds);
	//dup2(fds[1], 1);
	while (1)
	{
		if (count == ac - 1)
			break ;
		
		pid_t pid = fork();
		
		if (pid == 0)
		{
			char *find_str = ft_strjoin(*paths, av[count]);
			while (execve(find_str, 0, ev) == -1)
			{
				write(2, find_str, ft_strlen(find_str));
				write(2, " cmd failed\n", 12);
				free(find_str);
				++paths;
				find_str = ft_strjoin(*paths, av[count]);
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
			read(fds[0], buffer, BUFFER_SIZE);
			write(2, "read done!\n", 11);

			//write(fd[1], buffer, BUFFER_SIZE);
			//write(2, "write done!\n\n", 13);
		}
		++count;
	}
	write(2, "done while\n", 11);
	int out_fd = open(av[ac-1], O_WRONLY|O_CREAT);
	write(out_fd, buffer, BUFFER_SIZE);

    return 0;
}