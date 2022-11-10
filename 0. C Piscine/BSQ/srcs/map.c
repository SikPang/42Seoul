/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:43:33 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 11:54:07 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_t_map(void)
{
	t_map	*this;

	this = (t_map *)malloc(sizeof(t_map));
	check_null_after_malloc(this);
	this->grid = NULL;
	this->width = 0;
	this->height = 0;
	this->max_length = 0;
	this->x_max = 0;
	this->y_max = 0;
	this->empty = '\0';
	this->obstacle = '\0';
	this->full = '\0';
	return (this);
}

void	del_t_map(t_map *this)
{
	int	**grid;
	int	y;

	grid = this->grid;
	if (grid != NULL)
	{
		y = 0;
		while (y < this->height)
		{
			if (grid[y] != NULL)
				free(grid[y]);
			y++;
		}
		free(grid);
	}
	free(this);
}
