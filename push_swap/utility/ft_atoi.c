/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:06:44 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/07 19:12:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <unistd.h>
#include "../data_structure/deque.h"
#include <stdio.h>
static void	error_exit(t_deque *deque)
{
	free(deque->arr);
	//write(2, "Error\n", 6);
	printf("arg Error");
	exit(1);
}

static void	check_duplicate(t_deque *deque, int data)
{
	int	i;

	i = 0;
	while (i < deque->size)
	{
		if (deque->arr[i] == data)
			error_exit(deque);
		++i;
	}
}

static int	check_valid(int before_num, char ch, int minus)
{
	int	after_num;

	if (ch < '0' || ch > '9')
		return (0);
	if (minus == 1)
	{
		after_num = before_num * 10 + ch - '0';
		if (after_num < 0)
			return (0);
	}
	else
	{
		before_num *= -1;
		after_num = before_num * 10 - (ch - '0');
		if (after_num > 0)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str, t_deque *deque)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		++i;
	}
	while (str[i] != '\0')
	{
		if (!check_valid(num, str[i], minus))
			error_exit(deque);
		num = num * 10 + str[i] - '0';
		++i;
	}
	check_duplicate(deque, num * minus);
	return (num * minus);
}
