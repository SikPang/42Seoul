/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/13 19:30:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command.h"

#include <stdio.h>

void	optimize_commands(t_queue *que)
{
	t_node	*cur;
	t_node	*temp;
	
	cur = que->head;
	while (cur != 0 && cur->next_node != 0)
	{
		if (cur->data == PB && cur->next_node->data == PA)
		{
			temp = cur->prev_node;
			temp->next_node = cur->next_node->next_node;
			if (cur->next_node->next_node != 0)
				cur->next_node->next_node->prev_node = temp;
			free(cur->next_node);
			free(cur);
			cur = temp;
		}
		else
			cur = cur->next_node;
	}
}
