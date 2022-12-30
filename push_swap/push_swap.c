/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:15:03 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/30 17:28:09 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 각 스택을 옮겨가며 한 번의 전체 이동에서 제일 작은 수와 제일 큰 수를 찾는 과정
// 그 두개의 수는 스택의 맨 아래에 저장
// 이를 반복

// 스택1에서 스택2로 옮길 때 스택2의 top, bottom과 비교
// top보다 작으면 top으로 이동
// top보다 크고 bottom보다 작으면 top으로 이동 후 스왑
// top보다 크고 bottom보다 크면 top으로 이동 후 로테이트

// 한 번의 이동마다 카운트
// 카운트 * 2가 size 또는 size - 1에 도달하면 종료

// 한 번의 이동마다 카운트 / 2 만큼 로테이트하여 bottom에 저장

#include "push_swap.h"
#include "deque.h"

#include <stdio.h>
static void	store(t_deque *dest, t_deque *src, char check)
{
	while (src->size > 0)
	{
		push(dest, src, check);
		rotate(dest, src, check);
	}
}

static void	move_all(t_deque *dest, t_deque *src, int turn)
{
	char	check;
	
	check = 'a';
	if (turn % 2 == 0)
		check = 'b';
	while (src->size >= turn * 2)
	{
		if (dest->size == 0 || src->arr[src->head] < dest->arr[dest->head])
			push(dest, src, check);
		else
		{
			if (src->arr[src->head] > dest->arr[dest->tail])
			{
				push(dest, src, check);
				rotate(dest, src, check);
			}
			else
			{
				push(dest, src, check);
				swap(dest, src, check);
			}
		}
		//printf("%d\n", src->size);
	}
	store(dest, src, check);
}

// cnt가 홀수면 b에 쌓여있고, 짝수면 a에 쌓여있음
static void	finish(t_deque *deque1, t_deque *deque2, int turn)
{
	int	cnt;

	cnt = 0;
	if (turn % 2 == 0)
	{
		while (cnt < turn)
		{
			reverse_rotate(deque1, deque2, 'a');
			++cnt;
		}
	}
	else
		move_all(deque1, deque2, 0);
}

void	push_swap(t_deque *deque1, t_deque *deque2)
{
	int		turn;
	int		size;
	t_deque	*temp;

	turn = 0;
	size = deque1->size;
	while (turn * 2 < size - 1)
	{
		move_all(deque2, deque1, turn);
		temp = deque1;
		deque1 = deque2;
		deque2 = temp;
		++turn;
	}
	finish(deque1, deque2, turn);
}