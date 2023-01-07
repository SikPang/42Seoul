#include <stdlib.h>
#include <unistd.h>
#include "queue.h"

void	init_queue(t_queue *queue)
{
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
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
#include <stdio.h>
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
	free(head_node);
	--queue->size;
	return (data);
}

void	clean_queue(t_queue *que)
{
	t_node	*temp;
	t_node	*next;

	temp = que->head;
	while (temp != 0)
	{
		next = temp->next_node;
		free(temp);
		temp = next;
	}
}