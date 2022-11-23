/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:33:45 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 23:23:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	set_str(char* new_str, int n, int size)
{
	if (n < 10)
	{
		new_str[size - 1]= n + '0';
		return;
	}
	set_str(new_str, n / 10, size - 1);
	new_str[size - 1]= n % 10 + '0';
}

static int	get_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	if (i == 0)
		++i;
	return (i);
}

void	check_minus(long long *ln, int *size, int *is_minus, char *new_str)
{
	if (ln < 0)
	{
		++(*size);
		*is_minus = 1;
		(*ln) *= -1;
		new_str = (char *)ft_calloc(size + 2, sizeof(char));
	}
	else
	{
		*is_minus = 0;
		new_str = (char *)ft_calloc(size + 1, sizeof(char));
	}
	if (new_str == (char *)0)
		return ((char *)0);
}

char	*ft_itoa(int n)
{
	char		*new_str;
	int			size;
	int			is_minus;
	long long	ln;

	ln = (long long)n;
	size = 0;
	size += get_size(ln);
	check_minus(&ln, &size, &is_minus, new_str);
	if (is_minus == 1)
	{
		new_str[0] = '-';
		set_str(new_str + 1, n, size);
	}
	else
		set_str(new_str, n, size);
	return (new_str);
}

#include <stdio.h>
int main()
{
	printf("%s", ft_itoa(-100));
}