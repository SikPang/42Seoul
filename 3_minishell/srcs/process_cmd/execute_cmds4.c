/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:16:54 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/10 14:16:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmds.h"

void	free_2d_char(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		++i;
	}
	free(str);
}

void	p_error(t_list *cmd_que, t_list *parse_que, t_fds *fds)
{
	g_our_first_global_variable_it_has_signal_and_i_am_happy = 1;
	perror("minish: ");
	while (parse_que->head != NULL
		&& parse_que->head->data.type != PIPE)
		pop_front(parse_que);
	while (!is_empty(cmd_que))
		pop_front(cmd_que);
	if (fds->pipe_size == 0)
		dup2(fds->defaults[STDIN_FILENO], STDIN_FILENO);
}

void	set_default_to_std_fds(t_fds *fds)
{
	dup2(fds->defaults[STDIN_FILENO], STDIN_FILENO);
	dup2(fds->defaults[STDOUT_FILENO], STDOUT_FILENO);
}
