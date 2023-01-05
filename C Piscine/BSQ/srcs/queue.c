/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:47:57 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 11:28:02 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*new_t_queue(int max_size)
{
	t_queue	*this;

	this = (t_queue *)malloc(sizeof(t_queue));
	check_null_after_malloc(this);
	this->circular_queue = (char *)malloc(sizeof(char) * (max_size));
	check_null_after_malloc(this->circular_queue);
	this->max_size = max_size;
	this->front = -1;
	this->rear = -1;
	this->enque = t_queue_enque;
	this->deque = t_queue_deque;
	return (this);
}

void	del_t_queue(t_queue *this)
{
	free(this->circular_queue);
	free(this);
}

int	t_queue_enque(t_queue *this, char c)
{
	if ((this->front == 0 && this->rear == this->max_size - 1)
		|| (this->front == this->rear + 1))
	{
		ft_putstr("queue is full!\n");
		return (0);
	}
	if (this->front == -1)
		this->front = 0;
	this->rear = (this->rear + 1) % this->max_size;
	this->circular_queue[this->rear] = c;
	return (1);
}

char	t_queue_deque(t_queue *this)
{
	char	element;

	if (this->front == -1)
	{
		return (IS_EMPTY);
	}
	element = this->circular_queue[this->front];
	if (this->front == this->rear)
	{
		this->front = -1;
		this->rear = -1;
	}
	else
		this->front = (this->front + 1) % this->max_size;
	return (element);
}
