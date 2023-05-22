/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:50:15 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 16:24:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

_Bool	is_door_surrounded(t_info *info, t_vector2 cur)
{
	const int	direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	t_vector2	next;
	int			i;
	int			j;
	int			wall_count;

	j = -1;
	while (++j < 2)
	{
		wall_count = 0;
		i = j;
		while (i < 4)
		{
			next.x = cur.x + direction[i][0];
			next.y = cur.y + direction[i][1];
			if (next.x >= 0 && next.y >= 0
				&& next.x < info->width && next.y < info->height
				&& info->map[(int)next.y][(int)next.x] == '1')
				++wall_count;
			i += 2;
		}
		if (wall_count == 2)
			return (TRUE);
	}
	return (FALSE);
}

void	binding_sprite_path(t_info *info)
{
	info->sprite.source[0].path = SPRITE_PATH_1;
	info->sprite.source[1].path = SPRITE_PATH_2;
	info->sprite.source[2].path = SPRITE_PATH_3;
	info->sprite.source[3].path = SPRITE_PATH_4;
	info->sprite.source[4].path = SPRITE_PATH_5;
	info->sprite.source[5].path = SPRITE_PATH_6;
	info->sprite.source[6].path = SPRITE_PATH_7;
	info->sprite.source[7].path = SPRITE_PATH_8;
	info->sprite.source[8].path = SPRITE_PATH_9;
	info->sprite.source[9].path = SPRITE_PATH_10;
	info->sprite.source[10].path = SPRITE_PATH_11;
	info->sprite.source[11].path = SPRITE_PATH_12;
}

int	count_num_of_commas(char *str)
{
	int		num_of_commas;
	char	*cur;

	num_of_commas = 0;
	cur = str;
	while (*cur != '\0')
		if (*(cur++) == ',')
			num_of_commas++;
	return (num_of_commas);
}
