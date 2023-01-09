/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/09 19:24:21 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "command.h"

static void	print_commands2(int data)
{
	if (data == RA)
		write(1, "ra\n", 3);
	else if (data == RB)
		write(1, "rb\n", 3);
	else if (data == RR)
		write(1, "rr\n", 3);
	else if (data == RRA)
		write(1, "rra\n", 4);
	else if (data == RRB)
		write(1, "rrb\n", 4);
	else if (data == RRR)
		write(1, "rrr\n", 4);
}

void	print_commands(t_queue *que)
{
	t_node	*temp;

	temp = que->head;
	while (temp != 0)
	{
		if (temp->data == SA)
			write(1, "sa\n", 3);
		else if (temp->data == SB)
			write(1, "sb\n", 3);
		else if (temp->data == SS)
			write(1, "ss\n", 3);
		else if (temp->data == PA)
			write(1, "pa\n", 3);
		else if (temp->data == PB)
			write(1, "pb\n", 3);
		else
			print_commands2(temp->data);
		temp = temp->next_node;
	}
}