/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:35:59 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/15 07:02:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put(int nb)
{
	nb += '0';
	write(1, &nb, 1);
}

void	print_nbr(long long nb)
{
	if (nb < 10)
	{
		put(nb);
		return ;
	}
	print_nbr(nb / 10);
	put(nb % 10);
}

void	ft_putnbr(int nb)
{
	long long	lnb;

	lnb = (long long)nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	print_nbr(lnb);
}
