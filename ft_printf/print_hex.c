/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:01:35 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/09 22:48:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

// int	print_hex(long long num, char check)
// {
// 	char	arr[8];
// 	int		i;
// 	char	*hex_lower;
// 	char	*hex_upper;

// 	hex_lower = "0123456789abcdef";
// 	hex_upper = "0123456789ABCDEF";
// 	i = 7;
// 	while (num != 0)
// 	{
// 		if (check == 'x')
// 			arr[i] = hex_lower[(int)(num % 16)];
// 		else
// 			arr[i] = hex_upper[(int)(num % 16)];
// 		num /= 16;
// 		--i;
// 	}
// 	write(1, arr, 8);
// 	return (8);
// }

static void	set_str(long long ln, int *size, char *hex, char check)
{
	if (ln < 16)
	{
		print_char(ln + '0');
		++(*size);
		return ;
	}
	set_str(ln / 16, size, hex, check);
	print_char(ln % 16 + '0');
	++(*size);
}

int	print_hex(long long num, char check)
{
	int			size;
	char	*hex;

	hex = "0123456789abcdef0123456789ABCDEF";
	size = 0;
	if (num < 0)
	{
		print_char('-');
		++size;
		num = -1 * num;
	}
	set_str(num, &size, hex, check);
	return (size);
}