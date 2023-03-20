/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:06:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/07 16:26:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmds.h"

static void	free_all(t_list *parse_que, char **full_cmd, t_tree *envs)
{
	free_2d_char(full_cmd);
	destroy_list(&parse_que);
	destroy_tree_ev(&envs);
}

static void	child_process_with_path(t_tree *envs, t_fds *fd, char **full_cmd)
{
	char	**envp;
	int		i;

	envp = get_envp(envs);
	close_all_pipes(fd);
	i = 0;
	execve(full_cmd[0], full_cmd, envp);
	free_2d_char(envp);
}

static void	child_process(t_tree *envs, t_fds *fd, char **full_cmd)
{
	char	*abs_cmd_name;
	char	**paths;
	char	**envp;
	int		idx;

	envp = get_envp(envs);
	paths = get_paths(envs);
	close_all_pipes(fd);
	idx = mini_execve(full_cmd, envs, FALSE);
	if (idx != -1)
		exit(idx);
	else
	{
		idx = 0;
		while (paths[idx] != NULL)
		{
			abs_cmd_name = ft_strjoin_free(paths[idx], ft_strdup(full_cmd[0]),
					TRUE);
			execve(abs_cmd_name, full_cmd, envp);
			free(abs_cmd_name);
			++idx;
		}
	}
	free(paths);
	free_2d_char(envp);
}

static _Bool	is_a_builtin(t_tree *envs, t_fds *fd, char **full_cmd)
{
	int		e_code;

	if (fd->pipe_size == 0)
	{
		e_code = mini_execve(full_cmd, envs, TRUE);
		if (e_code != -1)
		{
			g_our_first_global_variable_it_has_signal_and_i_am_happy = e_code;
			return (TRUE);
		}
	}
	return (FALSE);
}

_Bool	execute(t_tree *envs, t_fds *fd, t_list *cmd_que, t_list *parse_que)
{
	char	**full_cmd;
	pid_t	pid;

	full_cmd = get_full_cmd(cmd_que);
	if (!is_a_builtin(envs, fd, full_cmd))
	{
		pid = fork();
		fd->last_pid = pid;
		if (pid == -1)
			handle_error_and_exit(ERROR_FORK);
		else if (pid == 0)
		{
			set_signal_policy_in_child();
			if (is_include_path(full_cmd[0]))
				child_process_with_path(envs, fd, full_cmd);
			else
				child_process(envs, fd, full_cmd);
			print_err("minish: ", full_cmd[0], ": command not found\n");
			free_all(parse_que, full_cmd, envs);
			exit(CMD_FAIL);
		}
	}
	free_2d_char(full_cmd);
	return (FALSE);
}
