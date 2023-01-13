/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:09:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/13 22:40:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
//#inlcude <unistd.h>
#include "sort.h"

// tail이 top, head가 bottom
#include <stdio.h>
static void	set_limit(t_queue *queue)
{
	t_node	*cur;

	queue->max = INT_MIN;
	queue->min = INT_MAX;
	cur = queue->head;
	while (cur != 0)
	{
		if (cur->data > queue->max)
			queue->max = cur->data;
		if (cur->data < queue->min)
			queue->min = cur->data;
		cur = cur->next_node;
	}
}

int	is_ascending(t_queue *que_a)
{
	if (que_a->head->data < que_a->head->next_node->data
		&& que_a->head->next_node->data < que_a->tail->data)
		return (1);
	else
		return (0);
}

void	mini_sort(t_queue *que_a)
{
	set_limit(que_a);
	if (que_a->size == 0 || que_a->max == que_a->min || is_ascending(que_a))
		return ;
	if (que_a->head->data == que_a->min)
	{
		printf("sa\n");
		printf("ra\n");
	}
	else if (que_a->head->data == que_a->max)
	{
		if (que_a->head->next_node->data == que_a->min)
			printf("ra\n");
		else
		{
			printf("sa\n");
			printf("rra\n");
		}
	}
	else
	{
		if (que_a->head->next_node->data == que_a->min)
			printf("sa\n");
		else
			printf("rra\n");
	}
}

static void	check_last(t_queue *que_b)
{
	printf("pa\n");
	if (que_b->head->data > que_b->tail->data)
	{
		printf("pa\n");
		printf("ra\n");
	}
	else
	{
		printf("ra\n");
		printf("pa\n");
	}
}

void	small_sort(t_queue *que_a)
{
	t_queue	que_b;
	t_node	*cur;

	set_limit(que_a);
	init_queue(&que_b);
	cur = que_a->head;
	while (cur != 0)
	{
		if (cur->data == que_a->max || cur->data == que_a->min)
		{
			push(&que_b, cur->data);
			cur = erase(que_a, cur);
			printf("pb\n");
		}
		else
		{
			cur = cur->next_node;
			printf("ra\n");
		}
	}
	mini_sort(que_a);
	check_last(&que_b);
	clean_queue(&que_b);
}
