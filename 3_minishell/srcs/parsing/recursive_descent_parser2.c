/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_parser2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:06:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/01 19:24:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recursive_descent_parser.h"
#include <stdio.h>
#include <stdlib.h>

_Bool	rdp_cmd_prefix(t_list *parse_que, t_node *start, t_node *end)
{
	t_node	*redirection;
	t_node	*cur;

	redirection = NULL;
	cur = start;
	while (TRUE)
	{
		if (is_redirection(cur))
			redirection = cur;
		if (cur == end)
			break ;
		cur = cur->next;
	}
	if (redirection == NULL)
		return (FALSE);
	if (redirection != start)
	{
		if (!rdp_cmd_prefix(parse_que, start, redirection->prev))
			return (FALSE);
	}
	if (!rdp_io_redirect(parse_que, redirection, end))
		return (FALSE);
	return (TRUE);
}

_Bool	rdp_cmd_suffix(t_list *parse_que, t_node *start, t_node *end)
{
	if (start == end)
	{
		if (start->data.type != WORD)
			return (FALSE);
		push_back(parse_que,
			(t_token){end->data.type, ft_strdup(end->data.str)});
	}
	else if (!is_redirection(end->prev))
	{
		if (!rdp_cmd_suffix(parse_que, start, end->prev)
			|| !rdp_cmd_suffix(parse_que, end, end))
			return (FALSE);
	}
	else
	{
		if (end->prev != start)
		{
			if (!rdp_cmd_suffix(parse_que, start, end->prev->prev))
				return (FALSE);
		}
		if (!rdp_io_redirect(parse_que, end->prev, end))
			return (FALSE);
	}
	return (TRUE);
}

_Bool	rdp_io_redirect(t_list *parse_que, t_node *start, t_node *end)
{
	if (start->next != end || !is_redirection(start) || end->data.type != WORD)
		return (FALSE);
	push_back(parse_que,
		(t_token){start->data.type, ft_strdup(start->data.str)});
	push_back(parse_que, (t_token){FILE_NAME, ft_strdup(end->data.str)});
	return (TRUE);
}
