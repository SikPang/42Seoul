/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:06:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/07 16:35:14 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmds.h"

static void	free_all(t_list	*cmd_que, t_fds *fds)
{
	destroy_list(&cmd_que);
	close_all_pipes(fds);
}

_Bool	exe_cmd(t_tree *envs, t_list *parse_que, t_list *cmd_que,
	t_fds *fds)
{
	int	exe_value;

	push_front(cmd_que, get_front(parse_que));
	exe_value = FALSE;
	if (parse_que->head->next == NULL)
	{
		exe_value = execute(envs, fds, cmd_que, parse_que);
		set_default_to_std_fds(fds);
	}
	return (exe_value);
}

_Bool	exe_pipe(t_tree *envs, t_list *parse_que, t_list *cmd_que,
	t_fds *fds)
{
	_Bool	exe_value;

	exe_value = FALSE;
	if (dup2(fds->pipe[fds->pipe_idx][WRITE], STDOUT_FILENO) == -1)
		return (TRUE);
	if (!is_empty(cmd_que))
		exe_value = execute(envs, fds, cmd_que, parse_que);
	set_default_to_std_fds(fds);
	if (exe_value == TRUE)
		return (TRUE);
	if (dup2(fds->pipe[fds->pipe_idx][READ], STDIN_FILENO) == -1)
		return (TRUE);
	++(fds->pipe_idx);
	return (FALSE);
}

_Bool	exe_redirect(t_list *parse_que)
{
	int		fd;
	char	*file_name;
	int		head_type;

	head_type = parse_que->head->data.type;
	file_name = parse_que->head->next->data.str;
	pop_front(parse_que);
	if (head_type == LESS)
	{
		fd = open(file_name, O_RDONLY);
		if (fd == -1 || dup2(fd, STDIN_FILENO) == -1)
			return (TRUE);
	}
	else
	{
		if (head_type == GREAT)
			fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1 || dup2(fd, STDOUT_FILENO) == -1)
			return (TRUE);
	}
	if (close(fd) == -1)
		return (TRUE);
	return (FALSE);
}

void	execute_cmds(t_tree *envs, t_list *parse_que, _Bool	error)
{
	t_list	*cmd_que;
	t_fds	*fds;

	fds = get_fds(parse_que->pipe_size);
	cmd_que = init_list();
	while (!is_empty(parse_que))
	{
		error = FALSE;
		if (parse_que->head->data.type == WORD)
			push_back(cmd_que, get_front(parse_que));
		else if (parse_que->head->data.type == CMD)
			error = exe_cmd(envs, parse_que, cmd_que, fds);
		else if (is_redirection(parse_que->head))
			error = exe_redirect(parse_que);
		else if (parse_que->head->data.type == PIPE)
			error = exe_pipe(envs, parse_que, cmd_que, fds);
		if (error)
			p_error(cmd_que, parse_que, fds);
		else
			pop_front(parse_que);
	}
	free_all(cmd_que, fds);
	wait_all(fds);
}
