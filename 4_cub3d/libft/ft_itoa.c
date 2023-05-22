/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:26:57 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 16:09:13 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// size_t, NULL, malloc()
#include <limits.h>	// INT_MIN

static size_t	ft_cal_len_str(int n)
{
	size_t	len_str;

	len_str = 0;
	if (n <= 0)
		len_str++;
	while (n != 0)
	{
		len_str++;
		n = n / 10;
	}
	return (len_str);
}

static void	ft_putnbr_to_str(char *const s, int n, size_t len_str)
{
	char	*front;

	front = s + len_str - 1;
	if (n == INT_MIN)
	{
		*(front--) = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		*s = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		*(front--) = '0' + (n % 10);
		n = n / 10;
	}
	*front = '0' + n;
	return ;
}

char	*ft_itoa(int n)
{
	size_t	len_str;
	char	*str;

	len_str = ft_cal_len_str(n);
	str = (char *)ft_calloc(len_str + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_putnbr_to_str(str, n, len_str);
	return (str);
}
