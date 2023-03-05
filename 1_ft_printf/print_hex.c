/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:01:35 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/10 19:29:17 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	print_char_hex(int num, int *size, char *hex, char check)
{
	int	result;

	if (check == 'X')
		result = print_char(hex[num + 16]);
	else
		result = print_char(hex[num]);
	if (result == -1)
		return (-1);
	++(*size);
	return (0);
}

static int	recursion(unsigned long long num, int *size, char *hex, char check)
{
	if (num < 16)
	{
		if (print_char_hex(num, size, hex, check) == -1)
			return (-1);
		return (0);
	}
	if (recursion(num / 16, size, hex, check) == -1)
		return (-1);
	if (print_char_hex(num % 16, size, hex, check) == -1)
		return (-1);
	return (0);
}

int	print_hex(unsigned int num, char check)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef0123456789ABCDEF";
	size = 0;
	if (recursion(num, &size, hex, check) == -1)
		return (-1);
	return (size);
}

int	print_address(unsigned long long addr)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef";
	size = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	recursion(addr, &size, hex, 'p');
	return (size);
}
