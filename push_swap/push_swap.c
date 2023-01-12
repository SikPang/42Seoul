/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:15:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/12 22:54:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "command.h"
#include "./data_structure/deque.h"
#include "./data_structure/queue.h"

// stack a to ->

// A bottom
// push	: ra
// pop	: rra

// B top
// push	: pb
// pop	: pa

// B bottom
// push	: pb rb
// pop	: rrb pa

#include <stdio.h>
static void	push_to_a(t_deque *deq_a, t_deque *deq_b, t_queue *cmds, int i)
{
	while (deq_b->front_size > 0)
	{
		c_reverse_rotate(deq_b, deq_a, 'b', cmds);
		c_push(deq_a, deq_b, 'a', cmds);
	}
	while (deq_b->back_size > 0)
	{
		c_push(deq_a, deq_b, 'a', cmds);
	}
	while (deq_a->front_size > 0)
	{
		c_reverse_rotate(deq_a, deq_b, 'a', cmds);
		if (i == deq_a->data_len - 2
			&& get_back(deq_a)[deq_a->data_len - i] == '1')
			c_push(deq_b, deq_a, 'b', cmds);
		// rra 하면서 더 큰 수 b로 넘겼음
	}
	if (i == deq_a->data_len - 2)
	{
		// b 스택 뒤집으면서 pa

	}
}

static void	push_to_b(t_deque *deq_a, t_deque *deq_b, t_queue *cmds, int i)
{
	int	j;
	
	j = 0;
	while (j < deq_a->capacity)
	{
		if (get_back(deq_a)[deq_a->data_len - i - 1] == '0')
			c_rotate(deq_a, deq_b, 'a', cmds);
		else if (get_back(deq_a)[deq_a->data_len - i - 1] == '1')
			c_push(deq_b, deq_a, 'b', cmds);
		else
		{
			c_push(deq_b, deq_a, 'b', cmds);
			c_rotate(deq_b, deq_a, 'b', cmds);
		}
		++j;
	}
}

void	push_swap(t_deque *deq_a, t_deque *deq_b)
{
	t_queue	commands;
	int		i;

	deq_a->back_size = deq_a->front_size;
	deq_a->front_size = 0;
	init_queue(&commands);
	i = 0;
	while (i < deq_a->data_len - 1)
	{
		push_to_b(deq_a, deq_b, &commands, i);
		push_to_a(deq_a, deq_b, &commands, i);
		++i;
	}
	optimize_commands(&commands);
	print_commands(&commands);
}

