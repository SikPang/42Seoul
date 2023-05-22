/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:20:39 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 14:25:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		perror_and_exit(error_malloc);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	push_back(t_list *list, t_data data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		perror_and_exit(error_malloc);
	new_node->data.str = NULL;
	new_node->data = data;
	new_node->next = NULL;
	if (list->size == 0)
	{
		list->head = new_node;
		list->tail = new_node;
		new_node->prev = NULL;
	}
	else
	{
		list->tail->next = new_node;
		new_node->prev = list->tail;
		list->tail = new_node;
	}
	++(list->size);
}

void	push_front(t_list *list, t_data data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		perror_and_exit(error_malloc);
	new_node->data.str = NULL;
	new_node->data = data;
	new_node->next = NULL;
	if (list->size == 0)
	{
		list->head = new_node;
		list->tail = new_node;
		new_node->prev = NULL;
	}
	else
	{
		list->head->prev = new_node;
		new_node->next = list->head;
		list->head = new_node;
	}
	++(list->size);
}

void	pop_back(t_list *list)
{
	t_node	*temp;

	if (list->size == 0)
		return ;
	temp = list->tail;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
	}
	free(temp->data.str);
	free(temp);
	--(list->size);
}

void	pop_front(t_list *list)
{
	t_node	*temp;

	if (list->size == 0)
		return ;
	temp = list->head;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->head->next->prev = NULL;
		list->head = list->head->next;
	}
	free(temp->data.str);
	free(temp);
	--(list->size);
}
