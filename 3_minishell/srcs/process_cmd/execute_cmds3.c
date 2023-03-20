/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:06:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/13 12:16:09 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmds.h"
#include <sys/wait.h>

_Bool	is_include_path(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (TRUE);
		++i;
	}
	return (FALSE);
}

char	**get_full_cmd(t_list *cmd_que)
{
	char	**full_cmd;
	int		idx;

	full_cmd = (char **)ft_calloc(((cmd_que)->size + 1), sizeof(char *));
	idx = 0;
	while (!is_empty(cmd_que))
	{
		full_cmd[idx] = get_front(cmd_que).str;
		pop_front(cmd_que);
		idx++;
	}
	return (full_cmd);
}

void	close_all_pipes(t_fds *fd)
{
	int	i;

	i = 0;
	while (fd->pipe[i] != NULL)
	{
		close(fd->pipe[i][READ]);
		close(fd->pipe[i][WRITE]);
		free(fd->pipe[i]);
		++i;
	}
	free(fd->pipe);
}

t_fds	*get_fds(int size)
{
	t_fds	*fd;
	int		i;

	fd = (t_fds *)malloc(sizeof(t_fds));
	if (fd == NULL)
		handle_error_and_exit(ERROR_MALLOC);
	fd->pipe = (int **)malloc((size + 1) * sizeof(int *));
	if (fd->pipe == NULL)
		handle_error_and_exit(ERROR_MALLOC);
	fd->pipe[size] = NULL;
	i = 0;
	while (i < size)
	{
		fd->pipe[i] = (int *)malloc(2 * sizeof(int));
		if (fd->pipe[i] == NULL)
			handle_error_and_exit(ERROR_MALLOC);
		if (pipe(fd->pipe[i]) == -1)
			handle_error_and_exit(ERROR_PIPE);
		++i;
	}
	fd->pipe_size = size;
	fd->pipe_idx = 0;
	fd->defaults[STDIN_FILENO] = dup(STDIN_FILENO);
	fd->defaults[STDOUT_FILENO] = dup(STDOUT_FILENO);
	return (fd);
}

void	wait_all(t_fds *fds)
{
	int		idx;
	int		stat;
	pid_t	child_pid;

	idx = 0;
	while (idx < fds->pipe_size + 1)
	{
		child_pid = wait(&stat);
		if (child_pid == fds->last_pid)
		{
			if ((((signed char)(((stat) & 0x7f) + 1) >> 1) > 0))
				g_our_first_global_variable_it_has_signal_and_i_am_happy
					= ((stat) & 0x7f) + 128;
			else
				g_our_first_global_variable_it_has_signal_and_i_am_happy
					= ((stat) & 0xff00) >> 8;
		}
		++idx;
	}
	set_default_to_std_fds(fds);
	free(fds);
}
