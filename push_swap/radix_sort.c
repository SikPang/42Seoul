/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:45:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/07 19:28:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./data_structure/queue.h"
#include "./data_structure/deque.h"
#include "./data_structure/array.h"

#include <stdio.h>
static void	push_to_que(t_queue *que, t_array *arr, int cnt)
{
	int	temp;
	int	i;
	int	j;
	
	j = 0;
	while (j < arr->size)
	{
		temp = arr->arr[j];
		i = 0;
		while (i < cnt)
		{
			temp /= 10;
			++i;
		}
		push(&que[temp % 10], arr->arr[j]);
		++j;
	}
}

static void	start_sort(t_array *arr)
{
	t_queue	que[10];
	int		cur_idx;
	int		i;
	int		j;

	i = 0;
	while (i < 10)
		init_queue(&que[i++]);
	i = 0;
	while (i < arr->max_cnt)
	{
		push_to_que(que, arr, i++);
		cur_idx = 0;
		j = -1;
		while (++j < 10)
			while (que[j].size > 0)
				arr->arr[cur_idx++] = pop(&que[j]);
	}
	i = 0;
	while (i < 10)
		clean_queue(&que[i++]);
}

static void	memdup(t_array *arr, t_queue *que)
{
	int	i;
	int	data;
	int	cnt;

	init_arr(arr, que->size);
	i = 0;
	while (que->size > 0)
	{
		data = pop(que);
		arr->arr[i++] = data;
		cnt = 0;
		while (data > 0)
		{
			data /= 10;
			++cnt;
		}
		if (cnt > arr->max_cnt)
			arr->max_cnt = cnt;
	}
}

static void	partition(t_deque *deq, t_array *neg, t_array *pos)
{
	t_queue	neg_que;
	t_queue	pos_que;
	int		data;
	int		i;

	i = 0;
	init_queue(&neg_que);
	init_queue(&pos_que);
	while (i < deq->size)
	{
		data = deq->arr[(i + 1) % deq->size];
		if (data < 0)
			push(&neg_que, -data);
		else
			push(&pos_que, data);
		++i;
	}
	memdup(neg, &neg_que);
	memdup(pos, &pos_que);
}

int *radix_sort(t_deque *deq)
{
	int		*result;
	t_array	negative;
	t_array	positive;
	int		i;

	partition(deq, &negative, &positive);
	start_sort(&negative);
	start_sort(&positive);
	result = (int *)malloc(deq->size * sizeof(int));
	i = -1;
	while (i < negative.size)
	{
		result[i] = -negative.arr[negative.size - 1 - i];
		++i;
	}
	while (i < positive.size + negative.size)
	{
		result[i] = positive.arr[i - negative.size];
		++i;
	}
	free(negative.arr);
	free(positive.arr);
	return (result);
}
