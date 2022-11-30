/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_combinations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:08:15 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/09 16:35:31 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	set_value(int col, t_set *set)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*set).arr[col][(*set).case_count][i] = (*set).temp[i];
		++i;
	}
	++(*set).case_count;
}

int	get_row_num(int col, t_set *set, int direction)
{
	if (direction == 0)
		return ((*set).num[2][col]);
	else
		return ((*set).num[3][col]);
}

int	check_value_to_right(int col, t_set *set)
{
	int	j;
	int	count;
	int	max;

	j = 0;
	count = 0;
	max = 0;
	while (j < 4)
	{
		if ((*set).temp[j] > max)
		{
			max = (*set).temp[j];
			++count;
		}
		++j;
	}
	if (count != get_row_num(col, set, 0))
		return (0);
	else
		return (1);
}

int	check_value_to_left(int col, t_set *set)
{
	int	j;
	int	count;
	int	max;

	j = 3;
	count = 0;
	max = 0;
	while (j > -1)
	{
		if ((*set).temp[j] > max)
		{
			max = (*set).temp[j];
			++count;
		}
		--j;
	}
	if (count != get_row_num(col, set, 1))
		return (0);
	else
		return (1);
}

void	make_combinations(int col, int depth, t_set *set)
{
	int	i;

	if (depth == 4)
	{
		if (check_value_to_right(col, set) == 1
			&& check_value_to_left(col, set) == 1)
			set_value(col, set);
		return ;
	}
	i = 0;
	while (i < 4)
	{
		if ((*set).visited[i] == 1)
		{
			++i;
			continue ;
		}
		(*set).visited[i] = 1;
		(*set).temp[depth] = i + 1;
		make_combinations(col, depth + 1, set);
		(*set).visited[i] = 0;
		(*set).temp[depth] = 0;
		++i;
	}
}
