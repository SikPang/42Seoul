/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:37:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/06 20:42:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "queue.h"

static int	*memdup(t_deque *src, int *max_cnt)
{
	int	*new;
	int	i;
	int	temp;
	int	cnt;

	new = (int *)malloc(src->size * sizeof(int));
	i = 0;
	cnt = 0;
	while (i < src->size)
	{
		new[i] = src->arr[i];
		temp = src->arr[i];
		while (temp > 0)
		{
			temp /= 10;
			++cnt;
		}
		if (cnt > *max_cnt)
			*max_cnt = cnt;
		++i;
	}
	return (new);
}

static void	push_to_que(t_queue *que, int *result, int cnt, int size)
{
	int	temp;
	int	i;
	int	j;
	
	j = 0;
	while (j < size)
	{
		temp = result[j];
		i = 0;
		while (i < cnt)
		{
			temp /= 10;
			++i;
		}
		push(&que[temp % 10], result[j]);
		++j;
	}
}

int *radix_sort(t_deque *src)
{
	t_queue	que[10];
	int		*result;
	int		max_cnt;
	int		cur_idx;
	int		i;

	i = 0;
	while (i < 10)
		init_queue(&que[i]);
	max_cnt = 0;
	result = memdup(src, &max_cnt);
	i = 0;
	while (i < max_cnt)
	{
		push_to_que(que, result, i, src->size);
		cur_idx = 0;
		while (que[i].size > 0)
		{
			result[cur_idx] = pop(&que[i]);
			++cur_idx;
		}
		++i;
	}
	return (result);
}
