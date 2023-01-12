/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/12 21:28:02 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command.h"

#include <stdio.h>
static t_node *remove_rra(t_node *cur, int size)
{
	t_node	*temp;

	while (size > 0)
	{
		cur->data = RA;
		cur = cur->next_node;
		--size;
	}
	while (cur != 0)
	{
		temp = cur->prev_node;
		cur->prev_node->next_node = cur->next_node;
		if (cur->next_node != 0)
			cur->next_node->prev_node = cur->prev_node;
		free(cur);
		cur = temp;
		cur = cur->next_node;
	}
	return (cur);
}

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

static void	check(t_node *first_pa, t_node *cur, int pa_size)
{
	int	size;
	
	if (first_pa != 0
		&& first_pa->prev_node->data == RA && cur->data == RRA)
	{
		size = count_size(first_pa, cur);
		if (size > 0)
		{
			remove_ra(first_pa, size);
			remove_rra(cur, pa_size);
		}
	}
}

void	optimize_commands(t_queue *que)
{
	t_node	*cur;
	t_node	*first_pa;
	int		pa_size;

	cur = que->head;
	first_pa = 0;
	while (cur != 0)
	{
		pa_size = 0;
		while (cur->data == PA)
		{
			if (first_pa == 0)
				first_pa = cur;
			cur = cur->next_node;
			++pa_size;
		}
		check(first_pa, cur, pa_size);
		first_pa = 0;
		if (cur != 0)
			cur = cur->next_node;
	}
}
