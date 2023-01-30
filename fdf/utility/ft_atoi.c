/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:06:44 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 21:33:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utility.h"
#include "../draw/draw.h"

#include <stdio.h>

static int	get_default_color(int z)
{
	if (z >= 15)
		return (COLOR_RED);
	else if (z >= 10)
		return (COLOR_ORANGE);
	else if (z >= 5)
		return (COLOR_YELLOW);
	else if (z >= 0)
		return (COLOR_GREEN);
	else if (z >= -5)
		return (COLOR_BLUE);
	else if (z >= -10)
		return (COLOR_NAVY);
	else
		return (COLOR_PURPLE);
}

static int	set_color(char *str, int z)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		color = ft_atoh(str + 3);
	else if (str[i] == '\0' || str[i] == '\n')
		color = get_default_color(z);
	else
		error_exit();
	return (color);
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

int	ft_atoi(char *str, int *color)
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
	while (str[i] != '\0' && str[i] != '\n' && str[i] != ',')
	{
		if (!check_valid(num, str[i], minus))
			error_exit();
		num = num * 10 + str[i] - '0';
		++i;
	}
	*color = set_color((char *)str + i, num);
	free(str);
	return (num * minus);
}
