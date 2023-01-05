/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:51:39 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/09 17:12:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	real_finish(t_set *set)
{
	int	row;
	int	col;
	int	i;
	int	temp;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 3)
		{
			i = row + 1;
			temp = (*set).temp_ver[row][col];
			while (i < 4)
			{
				if (temp == (*set).temp_ver[i][col])
					return (0);
				++i;
			}
			++row;
		}
		++col;
	}
	return (1);
}
