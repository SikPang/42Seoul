/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:24:26 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/15 07:59:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(long long nb, int base_length, char *base)
{
	if (nb < base_length)
	{
		write(1, &base[nb], 1);
		return ;
	}
	print_nbr(nb / base_length, base_length, base);
	write(1, &base[nb % base_length], 1);
}

int	check_base(char *base, int *base_length)
{
	int	is_duplicated[128];
	int	i;

	i = 0;
	while (i < 128)
		is_duplicated[i++] = 0;
	*base_length = 0;
	while (base[*base_length] != '\0')
	{
		if (is_duplicated[(int)base[*base_length]] == 1)
			return (0);
		else
			is_duplicated[(int)base[*base_length]] = 1;
		if (base[*base_length] == '+' || base[*base_length] == '-')
			return (0);
		++(*base_length);
	}
	if (base[0] == '\0' || *base_length == 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	lnb;
	int			base_length;

	if (check_base(base, &base_length) == 0)
		return ;
	lnb = (long long)nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	print_nbr(lnb, base_length, base);
}
