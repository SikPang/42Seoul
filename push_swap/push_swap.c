/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:15:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 18:38:02 by kwsong           ###   ########.fr       */
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
static void	push_to_a(t_deque *deq_a, t_deque *deq_b, t_queue *commands)
{
	while (deq_b->front_size > 0)
	{
		//printf("b size : %d, front : %d, back : %d\n", deq_b->size, deq_b->front_size, deq_b->back_size);
		c_reverse_rotate(deq_b, deq_a, 'b', commands);
		c_push(deq_a, deq_b, 'a', commands);
	}
	while (deq_b->back_size > 0)
	{
		//printf("b size : %d, front : %d, back : %d\n", deq_b->size, deq_b->front_size, deq_b->back_size);
		c_push(deq_a, deq_b, 'a', commands);
	}
	while (deq_a->front_size > 0)
	{
		c_reverse_rotate(deq_a, deq_b, 'a', commands);
	}
}

static void	push_to_b(t_deque *deq_a, t_deque *deq_b, t_queue *commands, int i)
{
	int	j;
	
	j = 0;
	while (j < deq_a->capacity)
	{
		printf("%s\n", get_front(deq_a));
		if (get_front(deq_a)[deq_a->data_len - i - 1] == '0')
			c_rotate(deq_a, deq_b, 'a', commands);
		else if (get_front(deq_a)[deq_a->data_len - i - 1] == '1')
			c_push(deq_b, deq_a, 'b', commands);
		else
		{
			printf("asdasd\n");
			c_push(deq_b, deq_a, 'b', commands);
			c_rotate(deq_b, deq_a, 'b', commands);
		}
		//printf("b size : %d, front : %d, back : %d\n", deq_b->size, deq_b->front_size, deq_b->back_size);
		++j;
	}
	printf("\n");
}

void	push_swap(t_deque *deq_a, t_deque *deq_b)
{
	t_queue	commands;
	int		i;

	init_queue(&commands);
	i = 0;
	while (i < deq_a->data_len)
	{
		push_to_b(deq_a, deq_b, &commands, i);
		push_to_a(deq_a, deq_b, &commands);
		++i;
	}
	print_commands(&commands);
}
