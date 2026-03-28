/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:47:48 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/20 11:18:16 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"
#include "map.h"

int	get_min(int num1, int num2, int num3)
{
	int	min;

	min = num1;
	if (num2 < min)
		min = num2;
	if (num3 < min)
		min = num3;
	return (min);
}

int	set_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == map->obstacle)
				map->grid[i][j] = 0;
			else if (map->grid[i][j] == map->empty)
				map->grid[i][j] = 1;
			else
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	find_square(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i != 0 && j != 0 && map->grid[i][j] == 1)
			{
				map->grid[i][j] = get_min(map->grid[i - 1][j],
						map->grid[i][j - 1], map->grid[i - 1][j - 1]) + 1;
				if (map->max_length < map->grid[i][j])
				{
					map->max_length = map->grid[i][j];
					map->x_max = j;
					map->y_max = i;
				}
			}
			++j;
		}
		++i;
	}
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 0)
				write(1, &map->obstacle, 1);
			else if (i >= map->y_max - (map->max_length - 1)
				&& i <= map->y_max
				&& j >= map->x_max - (map->max_length - 1)
				&& j <= map->x_max)
				write(1, &map->full, 1);
			else
				write(1, &map->empty, 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}
