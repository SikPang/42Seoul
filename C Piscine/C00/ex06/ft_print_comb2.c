/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:42:18 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/02 13:53:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_char_by_int(char *c, int n)
{
	if (n == 0)
	{
		c[0] = '0';
		c[1] = '0';
	}
	else if (n < 10)
	{
		c[0] = '0';
		c[1] = n + '0';
	}
	else
	{
		c[0] = n / 10 + '0';
		c[1] = n % 10 + '0';
	}
}

void	print_nums(int *arr)
{
	char	str1[2];
	char	str2[2];

	get_char_by_int(str1, arr[0]);
	get_char_by_int(str2, arr[1]);
	write(1, str1, 2);
	write(1, " ", 1);
	write(1, str2, 2);
	if (arr[0] != 98 || arr[1] != 99)
		write(1, ", ", 2);
}

void	dfs(int *arr, int depth, int max, int index)
{
	int		i;

	i = index;
	if (depth == max)
	{
		print_nums(arr);
		return ;
	}
	while (i < 100)
	{
		arr[depth] = i;
		dfs(arr, depth + 1, max, i + 1);
		++i;
	}
}

void	ft_print_comb2(void)
{
	int	arr[2];

	arr[0] = 0;
	arr[1] = 0;
	dfs(arr, 0, 2, 0);
}
