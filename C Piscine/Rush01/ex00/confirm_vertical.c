/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:17:49 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/09 22:39:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>

int	real_finish(t_set *set);

void	finish_value(int col, t_set *set, int *check_return)
{
	int		row;
	char	print;

	if (real_finish(set) == 0)
		return ;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			(*set).answer[row][col] = (*set).temp_ver[row][col];
			print = (*set).temp_ver[row][col] + '0';
			write(1, &print, 1);
			if (col != 3)
				write(1, " ", 1);
			++col;
		}
		write(1, "\n", 1);
		++row;
	}
	*check_return = 1;
}

int	check_value_to_down(int col, t_set *set)
{
	int	row;
	int	count;
	int	max;

	while (col < 4)
	{
		row = 0;
		count = 0;
		max = 0;
		while (row < 4)
		{
			if ((*set).temp_ver[row][col] > max)
			{
				max = (*set).temp_ver[row][col];
				++count;
			}
			++row;
		}
		if (count != (*set).num[0][col])
			return (0);
		++col;
	}
	return (1);
}

int	check_value_to_up(int col, t_set *set)
{
	int	row;
	int	count;
	int	max;

	while (col < 4)
	{
		row = 3;
		count = 0;
		max = 0;
		while (row > -1)
		{
			if ((*set).temp_ver[row][col] > max)
			{
				max = (*set).temp_ver[row][col];
				++count;
			}
			--row;
		}
		if (count != (*set).num[1][col])
			return (0);
		++col;
	}
	return (1);
}

void	set_nums_to_temp(int depth, int i, t_set *set)
{
	int	n;

	n = 0;
	while (n < 4)
	{
		(*set).temp_ver[depth][n] = (*set).arr[depth][i][n];
		++n;
	}
}

void	confirm_vertical(int depth, t_set *set, int *check_return)
{
	int	i;

	if (depth == 4)
	{
		if (check_value_to_down(0, set) && check_value_to_up(0, set))
			finish_value(0, set, check_return);
		return ;
	}
	i = 0;
	while (i < 24)
	{
		if ((*set).arr[depth][i][0] == 0)
			break ;
		set_nums_to_temp(depth, i, set);
		confirm_vertical(depth + 1, set, check_return);
		if (*check_return)
			return ;
		++i;
	}
}
