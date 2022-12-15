/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:06:44 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 21:32:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "deque.h"

static void	error_exit(t_deque *deque)
{
	free(deque);
	write(2, "Error\n", 6);
	exit(1);
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
			return (1);
	}
	else
	{
		before_num *= -1;
		after_num = before_num * 10 - (ch - '0');
		if (after_num > 0)
			return (1);
	}
	return (0);
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
	while (1)
	{
		if (!check_valid(num, str[i], minus))
			error_exit(deque);
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num * minus);
}
