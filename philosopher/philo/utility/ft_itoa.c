/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:33:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 13:04:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include <stdlib.h>

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

char	*ft_itoa(int n)
{
	char		*new_str;
	int			size;
	long long	ln;

	ln = (long long)n;
	size = get_size(ln);
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (new_str == (char *)0)
		error_exit(MALLOC);
	new_str[size] = '\0';
	set_str(new_str, ln, size);
	return (new_str);
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(9));
// 	printf("%s\n", ft_itoa(178));
// 	printf("%s\n", ft_itoa(152353));
// 	printf("%s\n", ft_itoa(1));
// 	printf("%s\n", ft_itoa(90890832));
// 	printf("%s\n", ft_itoa(INT_MAX));
// }