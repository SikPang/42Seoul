/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:26:14 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 20:29:17 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put(int nb, int fd)
{
	nb += '0';
	write(fd, &nb, 1);
}

void	print_nbr(long long nb, int fd)
{
	if (nb < 10)
	{
		put(nb, fd);
		return ;
	}
	print_nbr(nb / 10, fd);
	put(nb % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	lnb;
	char	temp;

	lnb = (long long)n;
	temp = '-';
	if (n < 0)
	{
		write(fd, &temp, 1);
		lnb *= -1;
	}
	print_nbr(lnb, fd);
}