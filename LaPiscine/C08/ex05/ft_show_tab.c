/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:43:34 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/19 15:46:05 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

void	print_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		print_string(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		print_string(par[i].copy);
		write(1, "\n", 1);
		++i;
	}
}
