/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:32:46 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 11:54:59 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

#define EMPTY		0
#define OBSTACLE	1
#define FULL		2

void	insert_map_info(t_map *map, char *str_num_of_line, char *map_chars)
{
	int	i;

	map->height = ft_atoi(str_num_of_line);
	map->grid = (int **)malloc(sizeof(int *) * map->height);
	check_null_after_malloc(map->grid);
	i = 0;
	while (i < map->height)
		map->grid[i++] = NULL;
	map->empty = map_chars[EMPTY];
	map->obstacle = map_chars[OBSTACLE];
	map->full = map_chars[FULL];
}

int	set_map_info(t_map *map, t_file *fp)
{
	char	*map_info;
	int		len_of_map_info;
	char	*str_num_of_line;
	char	*map_chars;

	map_info = fp->get_line(fp);
	if (map_info == NULL || ft_strlen(map_info) < 4)
		return (0);
	len_of_map_info = ft_strlen(map_info);
	str_num_of_line = (char *)malloc(sizeof(char) * (len_of_map_info - 2));
	check_null_after_malloc(str_num_of_line);
	ft_strlcpy(str_num_of_line, map_info, len_of_map_info - 2);
	map_chars = map_info + len_of_map_info - 3;
	if (!ft_str_is_numeric(str_num_of_line) || !ft_str_is_printable(map_chars))
	{
		free(str_num_of_line);
		return (0);
	}
	insert_map_info(map, str_num_of_line, map_chars);
	free(str_num_of_line);
	return (1);
}

int	map_to_grid(t_map *map, int grid_idx, char *line)
{
	int		str_idx;

	str_idx = 0;
	while (line[str_idx] != '\0')
	{
		if (line[str_idx] != map->empty && line[str_idx] != map->obstacle)
			return (0);
		str_idx++;
	}
	map->grid[grid_idx] = (int *)malloc(sizeof(int) * map->width);
	check_null_after_malloc(map->grid[grid_idx]);
	str_idx = 0;
	while (line[str_idx] != '\0')
	{
		map->grid[grid_idx][str_idx] = 1 * (line[str_idx] == map->empty);
		str_idx++;
	}
	return (1);
}

int	insert_map_to_grid(t_map *map, t_file *fp)
{
	char	*line;
	int		grid_idx;

	grid_idx = 0;
	while (grid_idx < map->height)
	{
		line = fp->get_line(fp);
		if (line == NULL)
			return (occur_error(line));
		if (grid_idx == 0)
		{
			map->width = ft_strlen(line);
			if (map->width == 0)
				return (occur_error(line));
		}
		else if (ft_strlen(line) != (unsigned int)map->width)
			return (occur_error(line));
		if (!map_to_grid(map, grid_idx, line))
			return (occur_error(line));
		grid_idx++;
	}
	line = fp->get_line(fp);
	if (line != NULL)
		return (occur_error(line));
	return (1);
}

t_map	*parsing_map(char *file_name)
{
	t_file	*fp;
	t_map	*map;

	if (file_name == NULL)
		return (NULL);
	fp = new_t_file(file_name);
	map = new_t_map();
	if (fp == NULL || map == NULL)
	{
		if (fp != NULL)
			del_t_file(fp);
		if (map != NULL)
			del_t_map(map);
		return (NULL);
	}
	if (!set_map_info(map, fp) || !insert_map_to_grid(map, fp))
	{
		if (fp != NULL)
			del_t_file(fp);
		if (map != NULL)
			del_t_map(map);
		return (NULL);
	}
	del_t_file(fp);
	return (map);
}
