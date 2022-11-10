/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:06:44 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 14:16:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		++i;
	}
	return (num * minus);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char *c1 = "12345";
// 	char *c2 = "    12345   ";
// 	char *c3 = "+12345";
// 	char *c4 = "-12345";
// 	char *c5 = "  ++12345  ";
// 	char *c6 = "    +123456789123456  ";
// 	char *c7 = "";
// 	char *c8; // segmentation fault
// 	printf("%d %d %d %d %d %d %d\n", ft_atoi(c1), ft_atoi(c2), ft_atoi(c3) 
// 	, ft_atoi(c4), ft_atoi(c5) , ft_atoi(c6) , ft_atoi(c7));
// 	printf("%d %d %d %d %d %d %d\n", atoi(c1), atoi(c2), atoi(c3) 
// 	, atoi(c4), atoi(c5) , atoi(c6) , atoi(c7));
// }