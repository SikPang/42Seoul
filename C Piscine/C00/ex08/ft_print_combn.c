/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:37:43 by kwsong            #+#    #+#             */
/*   Updated: 2022/09/30 08:32:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nums(int *arr, int max)
{
	int		i;
	char	c;

	i = 0;
	while (arr[i] != 10)
	{
		c = '0' + arr[i++];
		write(1, &c, 1);
	}
	if (arr[0] != 10 - max)
	{
		write(1, ", ", 2);
	}
}

void	dfs(int *arr, int depth, int max, int index)
{
	int		i;

	i = index;
	if (depth == max)
	{
		print_nums(arr, max);
		return ;
	}
	while (i < 10)
	{
		arr[depth] = i;
		dfs(arr, depth + 1, max, i + 1);
		++i;
	}
}

void	ft_print_combn(int n)
{
	int		arr[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i++] = 10;
	}
	dfs(arr, 0, n, 0);
}
