/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:58:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/10 15:04:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	convert(va_list ap, char c)
{
	if (c == 'c')
		return (print_char((char)va_arg(ap, int)));
	else if (c == 's')
		return (print_str((va_arg(ap, char *))));
	else if (c == 'p')
		return (print_address(va_arg(ap, unsigned long long)));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (print_decimal(va_arg(ap, int), c));
	else if (c == 'x' || c == 'X')
		return (print_hex(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (print_char('%'));
	else if (c == '\0')
		return (0);
	return (print_char(c));
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		num;

	i = 0;
	num = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			num += convert(ap, str[++i]);
		else
			num += print_char(str[i]);
		++i;
	}
	va_end(ap);
	return (num);
}
