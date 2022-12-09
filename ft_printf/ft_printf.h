/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:56:34 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/09 18:56:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	print_hex(long long num, char check);
int	print_decimal(int num, char check);
int	print_address(unsigned long long address);
int	print_str(char *str);
int	print_char(char c);
int	convert(va_list ap, char c);
int ft_printf(const char *str, ...);

#endif