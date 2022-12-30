/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:46:03 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/30 14:07:13 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ft_printf/ft_printf.h"

void	swap(t_deque *deque1, t_deque *deque2, char check)
{
	int	first;
	int	second;

	first = pop_back(deque1);
	second = pop_back(deque1);
	push_back(deque1, first);
	push_back(deque1, second);
	if (check == 's')
	{
		first = pop_back(deque2);
		second = pop_back(deque2);
		push_back(deque2, first);
		push_back(deque2, second);
	}
	ft_printf("s%c\n", check);
}

void	push(t_deque *dest, t_deque *src, char check)
{
	push_back(dest, pop_back(src));
	ft_printf("p%c\n", check);
}

void	rotate(t_deque *deque1, t_deque *deque2, char check)
{
	push_front(deque1, pop_back(deque1));
	if (check == 'r')
		push_front(deque2, pop_back(deque2));
	ft_printf("r%c\n", check);
}

void	reverse_rotate(t_deque *deque1, t_deque *deque2, char check)
{
	push_back(deque1, pop_front(deque1));
	if (check == 'r')
		push_back(deque2, pop_front(deque2));
	ft_printf("rr%c\n", check);
}
