/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:48:17 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 21:09:05 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "../utility/utility.h"

void	init_llist(t_llist *list)
{
	list->head = 0;
	list->tail = 0;
	list->size = 0;
	list->max = 0;
}

void	clean_llist(t_llist *list)
{
	t_lnode	*temp;
	t_lnode	*next;

	temp = list->head;
	while (temp != 0)
	{
		next = temp->next_node;
		clean_list(temp->data);
		free(temp);
		temp = next;
	}
}

void	push_list(t_llist *list)
{
	t_lnode	*new_node;

	new_node = (t_lnode *)malloc(sizeof(t_lnode));
	if (new_node == 0)
		error_exit();
	new_node->data = (t_list *)malloc(sizeof(t_list));
	init_list(new_node->data);
	if (list->size != 0 && list->tail->data->max > list->max)
		list->max = list->tail->data->max;
	new_node->next_node = 0;
	if (list->size == 0)
	{
		list->head = new_node;
		list->tail = new_node;
		new_node->prev_node = 0;
	}
	else
	{
		list->tail->next_node = new_node;
		new_node->prev_node = list->tail;
		list->tail = new_node;
	}
	++list->size;
}

void	pop_list(t_llist *list)
{
	t_lnode	*head_node;

	if (list->size == 0)
		error_exit();
	clean_list(list->head->data);
	head_node = list->head;
	list->head = list->head->next_node;
	if (list->size > 1)
		list->head->prev_node = 0;
	else
		list->tail = 0;
	free(head_node);
	--list->size;
}

t_lnode	*erase_list(t_llist *list, t_lnode *target)
{
	t_lnode	*next;

	next = target->next_node;
	if (target == list->head)
	{
		list->head = target->next_node;
		target->next_node->prev_node = 0;
	}
	else if (target == list->tail)
	{
		list->tail = target->prev_node;
		target->prev_node->next_node = 0;
	}
	else
	{
		target->next_node->prev_node = target->prev_node;
		target->prev_node->next_node = target->next_node;
	}
	free(target);
	--list->size;
	return (next);
}
