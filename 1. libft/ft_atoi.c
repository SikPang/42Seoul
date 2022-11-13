/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:06:44 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/13 16:49:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	check_over_flow(int before_num, char ch, int minus)
{
	int	after_num;

	after_num = before_num * 10 + ch - '0';
	if (after_num < 0 && before_num > 0)
	{
		if (minus == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_over_flow(num, str[i], minus) == 1)
			return (-1);
		else if (check_over_flow(num, str[i], minus) == -1)
			return (0);
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num * minus);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *c1 = "12345";
	char *c2 = "    12345   ";
	char *c3 = "+12345";
	char *c4 = "-12345";
	char *c5 = "  ++12345  ";
	char *c6 = "    +2147483648  ";
	char *c7 = "";
	char *c8; // segmentation fault
	printf("%d %d %d %d %d %d %d\n", ft_atoi(c1), ft_atoi(c2), ft_atoi(c3) 
	, ft_atoi(c4), ft_atoi(c5) , ft_atoi(c6) , ft_atoi(c7));
	printf("%d %d %d %d %d %d %d\n", atoi(c1), atoi(c2), atoi(c3) 
	, atoi(c4), atoi(c5) , atoi(c6) , atoi(c7));

	printf ("%d ", ft_atoi("99999999999999999999"));
	printf ("%d\n", ft_atoi("-99999999999999999999"));
	printf ("%d ", atoi("99999999999999999999"));
	printf ("%d\n", atoi("-99999999999999999999"));
}