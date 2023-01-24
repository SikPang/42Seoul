/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:16:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 17:56:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "../utility/utility.h"

void	init_list(t_list *list)
{
	list->head = 0;
	list->tail = 0;
	list->size = 0;
}

void	clean_list(t_list *list)
{
	t_node	*temp;
	t_node	*next;

	temp = list->head;
	while (temp != 0)
	{
		next = temp->next_node;
		free(temp);
		temp = next;
	}
}

void	push_arg(t_list *list, double z, double x, double y)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == 0)
		error_exit();
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
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

int	pop_arg(t_list *list)
{
	t_node	*head_node;
	int		data;

	if (list->size == 0)
		error_exit();
	data = list->head->z;
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

t_node	*erase_arg(t_list *list, t_node *target)
{
	t_node	*next;

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
