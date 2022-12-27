/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:54:52 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/23 21:14:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"

void	init_deque(t_deque *deque, int size)
{
	if (size <= 0)
		return ;
	deque->arr = (int *)malloc(size * sizeof(int));
	deque->size = size;
	deque->head = size / 2;
	deque->tail = size / 2;
}

void	push_front(t_deque *deque, int data)
{
	if (deque->head == 0)
		deque->head = deque->size - 1;
	else
		--deque->head;
	deque->arr[deque->head] = data;
}

void	push_back(t_deque *deque, int data)
{
	if (deque->tail == deque->size - 1)
		deque->tail = 0;
	else
		++deque->tail;
	deque->arr[deque->tail] = data;
}

int	pop_front(t_deque *deque)
{
	int	value;

	value = deque->arr[deque->head];
	if (deque->head == deque->head - 1)
		deque->head = 0;
	else
		++deque->head;
	return (value);
}

int	pop_back(t_deque *deque)
{
	int	value;

	value = deque->arr[deque->tail];
	if (deque->tail == 0)
		deque->tail = deque->size - 1;
	else
		--deque->tail;
	return (value);
}
