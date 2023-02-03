/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:47:22 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/03 14:45:21 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 30

int main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		count = 1;
	char	buffer[BUFFER_SIZE];

	int i = 0;
	while (envp[i] != 0)
	{
		printf("%s\n", envp[i]);
		++i;
	}

	pipe(fd);
	//int in_fd = open(argv[1], O_RDONLY);
	dup2(fd[1], 1);

	while (1)
	{
		if (count == argc - 1)
			break ;
		
		pid_t pid = fork();
		
		if (pid == 0)
			execv(argv[count], argv + count);
		else
		{
			write(2, "wait...\n", 8);
			wait(0);
			write(2, "wait done!\n", 11);

			write(2, "read...\n", 8);
			read(fd[0], buffer, BUFFER_SIZE);
			write(2, "read done!\n", 11);

			//write(fd[1], buffer, BUFFER_SIZE);
			//write(2, "write done!\n\n", 13);
		}
		++count;
	}
	write(2, "done while\n", 11);
	int out_fd = open(argv[argc-1], O_WRONLY|O_CREAT);
	write(out_fd, buffer, BUFFER_SIZE);

    return 0;
}