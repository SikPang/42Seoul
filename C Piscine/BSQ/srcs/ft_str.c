/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:55:30 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 10:31:35 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

int	ft_str_is_printable(char *str)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (c < 32 || c > 126)
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
