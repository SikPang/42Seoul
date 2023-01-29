/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:33:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/29 20:32:09 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

static void	set_str(char *result, unsigned int n, int size, char *hex)
{
	if (n < 16)
	{
		result[size - 1] = hex[n];
		return ;
	}
	set_str(result, n / 16, size - 1, hex);
	result[size - 1] = hex[n % 16];
}

char	*ft_itoh(unsigned int n)
{
	char	*result;
	char	*hex;
	int		size;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	size = get_size(n);
	result = (char *)malloc(9);
	if (result == 0)
		return (0);
	while (i < 9)
		result[i++] = '0';
	result[i] = '\0';
	set_str(result, n, size, hex);
	return (result);
}
