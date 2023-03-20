/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:06:00 by sokwon            #+#    #+#             */
/*   Updated: 2023/03/09 17:04:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>	// INT_MAX, INT_MIN

static _Bool	ft_isspace(const char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int	base;
	int	sign;

	if (str == NULL)
		return (0);
	base = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = 1 - (2 * (*(str++) == '-'));
	while (ft_isdigit(*str))
	{
		if (base > INT_MAX / 10 || (base == INT_MAX / 10 && *str > '7'))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		base = base * 10 + (*(str++) - '0');
	}
	return (sign * base);
}
