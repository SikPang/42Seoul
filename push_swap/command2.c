/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/12 21:01:53 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "command.h"

#include <stdio.h>
static t_node *remove_ra(t_node *cur, int size)
{
	t_node	*temp;

	cur = cur->prev_node;
	while (size > 0)
	{
		cur->data = RRA;
		cur = cur->prev_node;
		--size;
	}
	while (cur->data == RA)
	{
		temp = cur->next_node;
		cur->next_node->prev_node = cur->prev_node;
		cur->prev_node->next_node = cur->next_node;
		free(cur);
		cur = temp;
		cur = cur->prev_node;
	}
	return (cur);
}

static int	count_size(t_node *first, t_node *last)
{
	int	ra_size;
	int	rra_size;

	ra_size = 0;
	rra_size = 0;
	first = first->prev_node;
	while (first->data == RA)
	{
		++ra_size;
		first = first->prev_node;
	}
	while (last != 0 && last->data == RRA)
	{
		++rra_size;
		last = last->next_node;
	}
	//printf("---------- %d %d\n", rra_size, ra_size);
	if (rra_size > ra_size && ra_size - (rra_size - ra_size) > 0)
		return (rra_size - ra_size);
	else
		return (0);
}

void	optimize_commands(t_queue *que)
{
	t_node	*cur;
	t_node	*first_pa;
	int		size;

	cur = que->head;
	first_pa = 0;
	while (cur != 0)
	{
		while (cur->data == PA)
		{
			if (first_pa == 0)
				first_pa = cur;
			cur = cur->next_node;
		}
		if (first_pa != 0
			&& first_pa->prev_node->data == RA && cur->data == RRA)
		{
			size = count_size(first_pa, cur);
			if (size > 0)
				remove_ra(first_pa, size);
		}
		first_pa = 0;
		cur = cur->next_node;
	}
}

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
	t_node	*cur;

	cur = que->head;
	while (cur != 0)
	{
		if (cur->data == SA)
			write(1, "sa\n", 3);
		else if (cur->data == SB)
			write(1, "sb\n", 3);
		else if (cur->data == SS)
			write(1, "ss\n", 3);
		else if (cur->data == PA)
			write(1, "pa\n", 3);
		else if (cur->data == PB)
			write(1, "pb\n", 3);
		else
			print_commands2(cur->data);
		temp = cur->next_node;
		free(cur);
		cur = temp;
	}
}

