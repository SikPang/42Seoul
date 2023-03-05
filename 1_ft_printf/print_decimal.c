/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:01:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/10 19:04:09 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	recursion(long long ln, int *size)
{
	if (ln < 10)
	{
		if (print_char(ln + '0') == -1)
			return (-1);
		++(*size);
		return (0);
	}
	if (recursion(ln / 10, size) == -1)
		return (-1);
	if (print_char(ln % 10 + '0') == -1)
		return (-1);
	++(*size);
	return (0);
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
		if (print_char('-') == -1)
			return (-1);
		++size;
		ln = -1 * ln;
	}
	if (recursion(ln, &size) == -1)
		return (-1);
	return (size);
}
