/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:33:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 15:33:13 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utility.h"

static void	set_str(char *new_str, long long ln, int size)
{
	if (ln < 10)
	{
		new_str[size - 1] = ln + '0';
		return ;
	}
	set_str(new_str, ln / 10, size - 1);
	new_str[size - 1] = ln % 10 + '0';
}

static int	get_size(long long n)
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

static int	check_minus(long long *ln, int size, int *is_minus, char **new_str)
{
	if (*ln < 0)
	{
		*is_minus = 1;
		(*ln) *= -1;
		*new_str = (char *)malloc((size + 3) * sizeof(char));
	}
	else
	{
		*is_minus = 0;
		*new_str = (char *)malloc((size + 2) * sizeof(char));
	}
	if (*new_str == NULL)
		return (0);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char		*new_str;
	int			size;
	int			is_minus;
	long long	ln;

	ln = (long long)n;
	size = get_size(ln);
	new_str = NULL;
	if (check_minus(&ln, size, &is_minus, &new_str) == 0)
		return (NULL);
	new_str[0] = '/';
	if (is_minus == 1)
	{
		new_str[0] = '-';
		set_str(new_str + 1, ln, size);
	}
	else
		set_str(new_str + 1, ln, size);
	return (new_str);
}
