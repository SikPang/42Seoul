/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:20:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/03 13:05:01 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

static _Bool	find_node(t_list *list, t_node *target)
{
	t_node	*temp;

	temp = list->head;
	while (temp != NULL)
	{
		if (temp == target)
			return (TRUE);
		temp = temp->next;
	}
	return (FALSE);
}

void	erase_node(t_list *list, t_node *target)
{
	if (list->size == 0 || !find_node(list, target))
		return ;
	else if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else if (target == list->head)
	{
		list->head->next->prev = NULL;
		list->head = list->head->next;
	}
	else if (target == list->tail)
	{
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
	}
	else
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
	}
	free(target);
	--(list->size);
}

_Bool	is_empty(t_list *list)
{
	if (list->size == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	destroy_list(t_list **list_ref)
{
	t_node	*cur;
	t_node	*next;

	if (list_ref == NULL || *list_ref == NULL)
		return ;
	cur = (*list_ref)->head;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur->data.str);
		free(cur);
		cur = next;
	}
	free(*list_ref);
	*list_ref = NULL;
}

t_token	get_front(t_list *list)
{
	return ((t_token){list->head->data.type, ft_strdup(list->head->data.str)});
}
