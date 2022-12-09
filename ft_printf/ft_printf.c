/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:58:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/09 22:46:23 by kwsong           ###   ########.fr       */
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
	else if (c == 'd')
		return (print_decimal(va_arg(ap, int), 'd'));
	else if (c == 'i')
		return (print_decimal(va_arg(ap, int), 'i'));
	else if (c == 'u')
		return (print_decimal(va_arg(ap, int), 'u'));
	else if (c == 'x')
		return (print_hex(va_arg(ap, long long), 'x'));
	else if (c == 'X')
		return (print_hex(va_arg(ap, long long), 'X'));
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

#include <stdio.h>
#include <limits.h>

int main()
{
	int len1 = 0;
	int len2 = 0;
	
	//char
	char q = 'a';
	char w = 'b';
	//str
	char *test1 = "babo";
	char *test2 = "mae rong";
	len1 += printf	 ("p_c:%c, %c, %s, %s\n", q, w,test1, test2);
	len2 += ft_printf("my :%c, %c, %s, %s\n", q, w, test1, test2);
	printf("\n");

	//memory address
	char p = 'a';
	int pi = 35;
	char *pp = NULL;
	len1 += printf	 ("p_p:%p, %p, %p\n", &p, &pi, pp);
	len2 += ft_printf("my :%p, %p, %p\n", &p, &pi, pp);
	printf("\n");

	// digit
	int min = INT_MIN;
	int max = INT_MAX;
	len1 += printf	 ("p_d:%d, %d, %d\n", min-1, max+1, 0);
	len2 += ft_printf("my :%d, %d, %d\n", min-1, max+1, 0);
	printf("\n");

	// unsigned dec
	len1 += printf	 ("p_u:%u == %u\n", min, -1-max);
	len2 += ft_printf("my :%u == %u\n", min, -1-max);
	printf("\n");

	// unsigned hex
	len1 += printf	 ("p_x:%x, %x, %x\n", 12345, LONG_MAX, -1);
	len2 += ft_printf("my :%x, %x, %x\n", 12345, LONG_MAX, -1);
	printf("\n");

	// unsigned hex upper
	len1 += printf	 ("p_X:%X, %X, %X\n", max, LONG_MIN, -max);
	len2 += ft_printf("my :%X, %X, %X\n", max, LONG_MIN, -max);
	printf("\n");

	// // edgecase
	// len1 += printf	 ("p_error :%d%,% %s%%\n", min-1, test1);
	// len2 += ft_printf("my_error:%d%,% %s%%\n", min-1, test1);
	// len1 += printf	 ("p_error :%d\n", min-1);
	// len2 += ft_printf("my_error:%d\n", min-1);
	// len1 += printf("p_error :%$%\(*%d\n");
	// len2 += printf("my_error:%$%\(*%d\n");
	// printf("\n");

	// return value
	printf ("p_len :%d\n", len1);
	printf ("my_len:%d\n", len2);
}