/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:20:30 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/08 23:40:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	print_address(unsigned long long address)
{
	char				*hex;
	char				arr[14];
	int					i;

	if (address == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = "0123456789abcdef";
	i = 13;
	arr[0] = '0';
	arr[1] = 'x';
	while (address != 0)
	{
		arr[i] = hex[(int)(address % 16)];
		address /= 16;
		--i;
	}
	write(1, arr, 14);
	return (14);
}