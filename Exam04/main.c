#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_pipes
{
	int prev[2];
	int cur[2];
} t_pipes;

void print_error(char *text)
{
	int i = 0;

	while (text[i] != '\0')
	{
		write(2, text + i, 1);
		++i;
	}
	write(2, "\n", 1);
}

int execute_cmd(char **av, int start, int end, char **ev)
{
	av[end] = NULL;
	if (execve(av[start], av + start, ev) == -1)
	{
		print_error("error: cannot execute executable_that_failed");
		return -1;
	}
	return 0;
}

void close_pipe(int *fd)
{
	if (fd[0] != -1)
	{                                                                                                                                                                       
		close(fd[0]);
		fd[0] = -1;
	}
	if (fd[1] != -1)
	{
		close(fd[1]);
		fd[1] = -1;
	}
}

int main(int ac, char **av, char **ev)
{
	int stdin = dup(STDIN_FILENO);
	int stdout = dup(STDOUT_FILENO);
	int cur = 1;
	int end;
	int child_size = 1;
	int cnt = 0;

	t_pipes pipes;
	pipes.cur[0] = -1;
	pipes.cur[1] = -1;
	pipes.prev[0] = -1;
	pipes.prev[1] = -1;

	for (int i = 1; av[i] != NULL; ++i)
	{
		if (strcmp(av[i], "|") == 0)
			++(child_size);
	}

	(void)ac;
	while (av[cur] != NULL)
	{
		end = cur;

		while (av[end] != NULL && strcmp(av[end], "|") != 0 && strcmp(av[end], ";") != 0)
			++end;
		
		if (strcmp(av[cur], "cd") == 0)
		{
			if (end - cur != 2)
				print_error("error: cd: bad arguments");
			else if (chdir(av[end]) == -1)
				print_error("error: cd: cannot change directory to path_to_change");
		}
		else if (av[end] != NULL && strcmp(av[end], "|") == 0)
		{
			close_pipe(pipes.prev);

			pipes.prev[0] = pipes.cur[0];
			pipes.prev[1] = pipes.cur[1];

			pipe(pipes.cur);

			if (fork() == 0)
			{
				if (cnt == 0)
				{
					dup2(pipes.cur[1], STDOUT_FILENO);
					close_pipe(pipes.cur);
				}
				else
				{
					dup2(pipes.prev[0], STDIN_FILENO);
					dup2(pipes.cur[1], STDOUT_FILENO);
					close_pipe(pipes.prev);
					close_pipe(pipes.cur);
				}

				if (execute_cmd(av, cur, end, ev) == -1)
					return 1;
			}
			++cnt;
		}
		else
		{
			if (fork() == 0)
			{
				if (pipes.cur[0] != -1)
				{
					dup2(pipes.cur[0], STDIN_FILENO);
				}
				dup2(stdout, STDOUT_FILENO);
				close_pipe(pipes.prev);
				close_pipe(pipes.cur);
				
				if (execute_cmd(av, cur, end, ev) == -1)
					return 1;
			}
			close_pipe(pipes.prev);
			close_pipe(pipes.cur);
			for (int i = 0; i < child_size; ++i)
				waitpid(-1, NULL, 0);

			dup2(stdin, STDIN_FILENO);
		}

		if (av[end] == NULL)
			break;
		cur = end + 1;
	}

	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
	close(stdin);
	close(stdout);
}