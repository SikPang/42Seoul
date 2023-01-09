/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:58:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/10 19:06:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	convert(va_list ap, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = print_char((char)va_arg(ap, int));
	else if (c == 's')
		result = print_str((va_arg(ap, char *)));
	else if (c == 'p')
		result = print_address(va_arg(ap, void *));
	else if (c == 'd' || c == 'i' || c == 'u')
		result = print_decimal(va_arg(ap, int), c);
	else if (c == 'x' || c == 'X')
		result = print_hex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		result = print_char('%');
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;
	int		temp;

	i = 0;
	num = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			temp = convert(ap, str[++i]);
		else
			temp = print_char(str[i]);
		num += temp;
		++i;
	}
	va_end(ap);
	return (num);
}
