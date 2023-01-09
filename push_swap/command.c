/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:46:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/09 18:01:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <unistd.h>
#include "command.h"

#include <stdio.h>
void	c_swap(t_deque *deq1, t_deque *deq2, char chk, t_queue *que)
{
	char	*first;
	char	*second;

	first = pop_back(deq1);
	second = pop_back(deq1);
	push_back(deq1, first);
	push_back(deq1, second);
	if (chk == 'a')
		push(que, SA);
	else if (chk == 'b')
		push(que, SB);
	else if (chk == 's')
	{
		first = pop_back(deq2);
		second = pop_back(deq2);
		push_back(deq2, first);
		push_back(deq2, second);
		push(que, SS);
	}
}

void	c_push(t_deque *dest, t_deque *src, char chk, t_queue *que)
{
	push_back(dest, pop_back(src));
	if (chk == 'a')
		push(que, PA);
	else if (chk == 'b')
		push(que, PB);
}

void	c_rotate(t_deque *deq1, t_deque *deq2, char chk, t_queue *que)
{
	push_front(deq1, pop_back(deq1));
	if (chk == 'a')
		push(que, RA);
	else if (chk == 'b')
		push(que, RB);
	else if (chk == 'r')
	{
		push_front(deq2, pop_back(deq2));
		push(que, RR);
	}
}

void	c_reverse_rotate(t_deque *deq1, t_deque *deq2, char chk, t_queue *que)
{
	push_back(deq1, pop_front(deq1));
	if (chk == 'a')
		push(que, RRA);
	else if (chk == 'b')
		push(que, RRB);
	else if (chk == 'r')
	{
		push_back(deq2, pop_front(deq2));
		push(que, RRR);
	}
}

// void	print_commands(t_queue *que)
// {
// 	que->
// }
