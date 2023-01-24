/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:48:17 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 16:01:07 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "../utility/utility.h"

void	init_list(t_llist *list)
{
	list->head = 0;
	list->tail = 0;
	list->size = 0;
}

void	clean_list(t_llist *list)
{
	t_lnode	*temp;
	t_lnode	*next;

	temp = list->head;
	while (temp != 0)
	{
		next = temp->next_node;
		free(temp);
		temp = next;
	}
}

void	push_back(t_llist *list, t_list data)
{
	t_lnode	*new_node;

	new_node = (t_lnode *)malloc(sizeof(t_lnode));
	if (new_node == 0)
		error_exit();
	new_node->data = data;
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

t_list	pop_back(t_llist *list)
{
	t_lnode	*head_node;
	t_list	data;

	if (list->size == 0)
		error_exit();
	data = list->head->data;
	head_node = list->head;
	list->head = list->head->next_node;
	if (list->size > 1)
		list->head->prev_node = 0;
	else
		list->tail = 0;
	free(head_node);
	--list->size;
	return (data);
}

t_lnode	*erase(t_list *que, t_lnode *target)
{
	t_lnode	*next;

	next = target->next_node;
	if (target == que->head)
	{
		que->head = target->next_node;
		target->next_node->prev_node = 0;
	}
	else if (target == que->tail)
	{
		que->tail = target->prev_node;
		target->prev_node->next_node = 0;
	}
	else
	{
		target->next_node->prev_node = target->prev_node;
		target->prev_node->next_node = target->next_node;
	}
	free(target);
	--que->size;
	return (next);
}
