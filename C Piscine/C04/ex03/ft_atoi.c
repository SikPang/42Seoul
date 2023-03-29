/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:37:25 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/15 17:20:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calculate_minus(char *str, int i, int *minus)
{
	int	count;

	count = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			++count;
		++i;
	}
	if (count % 2 == 1)
		*minus = -1;
	else
		*minus = 1;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	num;

	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	i = calculate_minus(str, i, &minus);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		++i;
	}
	return (num * minus);
}
