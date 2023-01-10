/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:54:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 18:33:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"

#include <stdio.h>
void	init_deque(t_deque *deque, int capacity)
{
	if (capacity <= 0)
		return ;
	deque->arr = (char **)malloc((capacity + 1) * sizeof(char *));
	deque->arr[capacity] = 0;
	deque->capacity = capacity;
	deque->size = 0;
	deque->head = -1;
	deque->tail = -1;
	deque->data_len = 0;
	deque->front_size = 0;
	deque->back_size = 0;
}

void	push_front(t_deque *deque, char *data)
{
	if (deque->size == deque->capacity)
	{
		//write(2, "Error\n", 6);
		printf("Error : push into full deque\n");
		exit(1);
	}
	if (deque->head == -1)
	{
		deque->head = 0;
		deque->tail = 0;
	}
	else if (deque->head == 0)
		deque->head = deque->capacity - 1;
	else
		--deque->head;
	deque->arr[deque->head] = data;
	++deque->size;
	++deque->front_size;
}

void	push_back(t_deque *deque, char *data)
{
	if (deque->size == deque->capacity)
	{
		//write(2, "Error\n", 6);
		printf("Error : push into full deque\n");
		exit(1);
	}
	if (deque->head == -1)
	{
		deque->head = 0;
		deque->tail = 0;
	}
	else if (deque->tail == deque->capacity - 1)
		deque->tail = 0;
	else
		++deque->tail;
	deque->arr[deque->tail] = data;
	++deque->size;
	++deque->back_size;
}

char	*pop_front(t_deque *deque)
{
	char	*value;

	if (deque->size == 0)
	{
		//write(2, "Error\n", 6);
		printf("Error : pop at empty deque\n");
		exit(1);
	}
	value = deque->arr[deque->head];
	if (deque->size == 1)
	{
		deque->head = -1;
		deque->tail = -1;
	}
	else if (deque->head == deque->capacity - 1)
		deque->head = 0;
	else
		++deque->head;
	--deque->size;
	--deque->front_size;
	return (value);
}

char	*pop_back(t_deque *deque)
{
	char	*value;

	if (deque->size == 0)
	{
		//write(2, "Error\n", 6);
		printf("Error : pop at empty deque\n");
		exit(1);
	}
	value = deque->arr[deque->tail];
	if (deque->size == 1)
	{
		deque->head = -1;
		deque->tail = -1;
	}
	else if (deque->tail == 0)
		deque->tail = deque->capacity - 1;
	else
		--deque->tail;
	--deque->size;
	--deque->back_size;
	return (value);
}
