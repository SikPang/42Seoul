/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:57:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/02 13:01:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_digit(int nb)
{
	int	digit;

	digit = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		digit *= 10;
	}
	return (digit);
}

void	print_num(int num)
{
	char	c;

	c = num + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	num;
	int	digit;
	int	is_minus;
	int	prev_num;

	prev_num = 0;
	if (nb < 0)
		is_minus = 1;
	else
		is_minus = 0;
	digit = get_digit(nb);
	if (is_minus)
		write(1, "-", 1);
	while (digit != 0)
	{
		num = nb / digit;
		if (is_minus)
			num = -num;
		num -= prev_num;
		print_num(num);
		prev_num = prev_num * 10 + num * 10;
		digit /= 10;
	}
}
