/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_parser1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:42:19 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/10 16:50:19 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recursive_descent_parser.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*rdp_start(t_node *start, t_node *end)
{
	t_list	*parse_que;

	parse_que = init_list();
	if (start != NULL)
	{
		if (!rdp_pipe(parse_que, start, end))
		{
			destroy_list(&parse_que);
			return (NULL);
		}
	}
	return (parse_que);
}

_Bool	rdp_pipe(t_list *parse_que, t_node *start, t_node *end)
{
	t_node	*cur;

	cur = start;
	while (cur != end && cur->data.type != PIPE)
		cur = cur->next;
	if (cur->data.type == PIPE)
	{
		if (cur->prev == NULL || cur->next == NULL
			|| cur == start
			|| cur->next->data.type == PIPE
			|| !rdp_command(parse_que, start, cur->prev))
			return (FALSE);
		push_back(parse_que,
			(t_token){cur->data.type, ft_strdup(cur->data.str)});
		++(parse_que->pipe_size);
		if (!rdp_pipe(parse_que, cur->next, end))
			return (FALSE);
	}
	else
	{
		if (!rdp_command(parse_que, start, end))
			return (FALSE);
	}
	return (TRUE);
}

_Bool	rdp_command(t_list *p_que, t_node *start, t_node *end)
{
	t_node	*cmd_name;
	t_node	*cur;

	cmd_name = NULL;
	cur = start;
	while (TRUE)
	{
		if (cur->data.type == WORD
			&& (cur == start || !is_redirection(cur->prev)))
		{
			cmd_name = cur;
			break ;
		}
		if (cur == end)
			break ;
		cur = cur->next;
	}
	if (cmd_name == NULL)
		return (rdp_cmd_prefix(p_que, start, end));
	if (cmd_name != start && !rdp_cmd_prefix(p_que, start, cmd_name->prev))
		return (FALSE);
	if (cmd_name != end && !rdp_cmd_suffix(p_que, cmd_name->next, end))
		return (FALSE);
	push_back(p_que, (t_token){CMD, ft_strdup(cur->data.str)});
	return (TRUE);
}
