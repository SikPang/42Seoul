/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:48:14 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 16:23:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_split(char **strs)
{
	char	**cur;

	cur = strs;
	while (*cur != NULL)
	{
		free(*cur);
		cur++;
	}
	free(strs);
}

_Bool	is_color_string(char *arg)
{
	int	base;
	int	sign;

	sign = 1;
	if (*arg == '-' || *arg == '+')
		sign = 1 - 2 * (*arg++ == '-');
	if (sign == -1 || *arg == '\0')
		return (0);
	base = 0;
	while (*arg != '\0')
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		if (base > UCHAR_MAX / 10
			|| (base == UCHAR_MAX / 10 && *arg > '5'))
			return (0);
		base = base * 10 + (*arg - '0');
		arg++;
	}
	return (1);
}

int	get_color(char *color_data)
{
	char	**color_strs;
	int		num_of_chunk;
	int		color;

	if (count_num_of_commas(color_data) != 2)
		perror_and_exit(error_map_elems);
	color_strs = ft_split(color_data, ',');
	num_of_chunk = 0;
	while (color_strs[num_of_chunk] != NULL)
		num_of_chunk++;
	if (num_of_chunk != 3)
		perror_and_exit(error_map_elems);
	if (!is_color_string(color_strs[0])
		|| !is_color_string(color_strs[1])
		|| !is_color_string(color_strs[2]))
		perror_and_exit(error_map_elems);
	color = 0;
	color |= ft_atoi(color_strs[0]) << 16;
	color |= ft_atoi(color_strs[1]) << 8;
	color |= ft_atoi(color_strs[2]);
	free_split(color_strs);
	return (color);
}

void	check_valid(t_info *new, char c, t_vector2 pos)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (new->player.x != 0 || new->player.y != 0)
			perror_and_exit(error_map_elems);
		new->player.x = pos.x + 0.5f;
		new->player.y = pos.y + 0.5f;
	}
	else if (c == '3')
		push_back(new->sprite_list,
			(t_data){.vec = (t_vector2){pos.x + 0.5, pos.y + 0.5}});
	else if (c == '4' || c == '5')
		push_back(new->door_list, (t_data){.vec = pos});
	else if (c != '0' && c != '1' && c != ' ')
		perror_and_exit(error_map_elems);
}

void	check_side(t_info *new)
{
	int	cur_pos_x;
	int	cur_pos_y;

	cur_pos_y = 0;
	while (cur_pos_y < new->height)
	{
		cur_pos_x = -1;
		while (++cur_pos_x < new->width)
		{
			if (cur_pos_y != 0 && cur_pos_x != 0
				&& cur_pos_y != new->height - 1 && cur_pos_x != new->width - 1)
				continue ;
			if (new->map[cur_pos_y][cur_pos_x] != '1'
				&& new->map[cur_pos_y][cur_pos_x] != ' ')
				perror_and_exit(error_map_elems);
		}
		++cur_pos_y;
	}
}
