/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:16:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 19:19:03 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
//#include <unistd.h>
#include "queue.h"

#include <stdio.h>
void	init_queue(t_queue *queue)
{
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
	queue->max = INT_MIN;
}

void	clean_queue(t_queue *queue)
{
	t_node	*temp;
	t_node	*next;

	temp = queue->head;
	while (temp != 0)
	{
		next = temp->next_node;
		free(temp);
		temp = next;
	}
}

void	push(t_queue *queue, int data)
{
	t_node	*new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next_node = 0;
	if (queue->size == 0)
	{
		queue->head = new_node;
		queue->tail = new_node;
		new_node->prev_node = 0;
	}
	else
	{
		queue->tail->next_node = new_node;
		new_node->prev_node = queue->tail;
		queue->tail = new_node;
	}
	++queue->size;
}

int	pop(t_queue *queue)
{
	t_node	*head_node;
	int		data;

	if (queue->size == 0)
	{
		//write(2, "Error\n", 6);
		printf("Error : pop at empty queue\n");
		exit(1);
	}
	data = queue->head->data;
	head_node = queue->head;
	queue->head = queue->head->next_node;
	if (queue->size > 1)
		queue->head->prev_node = 0;
	else
		queue->tail = 0;
	free(head_node);
	--queue->size;
	return (data);
}
