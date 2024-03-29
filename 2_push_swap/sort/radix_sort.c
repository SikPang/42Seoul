/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:45:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/13 20:59:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../data_structure/array.h"
#include "../utility/utility.h"
#include "sort.h"

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

static void	partition(t_queue *que, t_array *neg, t_array *pos)
{
	t_queue	neg_que;
	t_queue	pos_que;
	t_node	*temp;
	int		data;

	init_queue(&neg_que);
	init_queue(&pos_que);
	temp = que->head;
	while (temp != 0)
	{
		data = temp->data;
		if (data < 0)
			push(&neg_que, -data);
		else
			push(&pos_que, data);
		temp = temp->next_node;
	}
	memdup(neg, &neg_que);
	memdup(pos, &pos_que);
}

int	*radix_sort(t_queue *que)
{
	int		*result;
	t_array	negative;
	t_array	positive;
	int		i;

	partition(que, &negative, &positive);
	start_sort(&negative);
	start_sort(&positive);
	result = (int *)malloc(que->size * sizeof(int));
	if (result == 0)
		error_exit();
	i = 0;
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
