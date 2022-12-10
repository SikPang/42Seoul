/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:01:35 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/10 15:32:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	print_char_hex(int num, int *size, char *hex, char check)
{
	if (check == 'X')
		print_char(hex[num + 16]);
	else
		print_char(hex[num]);
	++(*size);
}

static void	recursion(unsigned long long num, int *size, char *hex, char check)
{
	if (num < 16)
	{
		print_char_hex(num, size, hex, check);
		return ;
	}
	recursion(num / 16, size, hex, check);
	print_char_hex(num % 16, size, hex, check);
}

int	print_hex(unsigned int num, char check)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef0123456789ABCDEF";
	size = 0;
	recursion(num, &size, hex, check);
	return (size);
}

int	print_address(unsigned long long addr)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef";
	size = 2;
	write(1, "0x", 2);
	recursion(addr, &size, hex, 'p');
	return (size);
}
