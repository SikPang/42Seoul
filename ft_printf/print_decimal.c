/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:01:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/10 15:24:46 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	recursion(long long ln, int *size)
{
	if (ln < 10)
	{
		print_char(ln + '0');
		++(*size);
		return ;
	}
	recursion(ln / 10, size);
	print_char(ln % 10 + '0');
	++(*size);
}

int	print_decimal(int num, char check)
{
	long long	ln;
	int			size;

	size = 0;
	if (check == 'u')
		ln = (unsigned int)num;
	else
		ln = num;
	if (ln < 0)
	{
		print_char('-');
		++size;
		ln = -1 * ln;
	}
	recursion(ln, &size);
	return (size);
}
