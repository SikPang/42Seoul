/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yha <yha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:13 by yha               #+#    #+#             */
/*   Updated: 2022/10/09 22:40:11 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <unistd.h>

void	make_combinations(int col, int depth, t_set *set);

void	confirm_vertical(int depth, t_set *set, int *check_return);

void	initialize_struct(t_set *set)
{
	int	i;
	int	j;

	i = 0;
	(*set).case_count = 0;
	while (i < 4)
	{
		(*set).visited[i] = 0;
		++i;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 24)
		{
			(*set).arr[i][j][0] = 0;
			++j;
		}
		++i;
	}
	(*set).answer[0][0] = 0;
}

void	rush(t_set *set)
{
	int	i;
	int	check_return;

	initialize_struct(set);
	i = 0;
	check_return = 0;
	while (i < 4)
	{
		make_combinations(i++, 0, set);
		(*set).case_count = 0;
	}
	i = 0;
	confirm_vertical(0, set, &check_return);
	if ((*set).answer[0][0] == 0)
	{
		write(2, "Error\n", 6);
	}
}
