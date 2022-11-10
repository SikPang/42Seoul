/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:39:53 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/12 20:23:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_queens(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
}

int	check_select(int depth, int i, int *arr)
{
	int	j;

	j = 0;
	while (j < depth)
	{
		if (arr[j] == i
			|| arr[j] - j == i - depth
			|| arr[j] + j == i + depth)
			return (0);
		++j;
	}
	return (1);
}

void	start_ten_queen(int depth, int *arr, int *count)
{
	int	i;

	if (depth == 10)
	{
		print_queens(arr);
		++(*count);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (depth != 0 && check_select(depth, i, arr) == 0)
		{
			++i;
			continue ;
		}
		arr[depth] = i;
		start_ten_queen(depth + 1, arr, count);
		arr[depth] = 0;
		++i;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	count;

	count = 0;
	start_ten_queen(0, arr, &count);
	return (count);
}
