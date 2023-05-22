/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:46:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 16:05:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	check_texture(t_info *new)
{
	int	i;

	i = 0;
	new->textures[DOOR_OPENED].path = DOOR_OPENED_PATH;
	new->textures[DOOR_CLOSED].path = DOOR_CLOSED_PATH;
	new->textures[DOOR_SIDE].path = DOOR_SIDE_PATH;
	while (i < WALL_TEXTURE_SIZE + DOOR_TEXTURE_SIZE)
	{
		new->textures[i].img = mlx_xpm_file_to_image(new->canvas->mlx,
				new->textures[i].path, &new->textures[i].width,
				&new->textures[i].height);
		if (new->textures[i].img == NULL)
			perror_and_exit(error_map_elems);
		new->textures[i].data = mlx_get_data_addr(new->textures[i].img,
				&new->textures[i].bits_per_pixel, &new->textures[i].size_line,
				&new->textures[i].endian);
		if (new->textures[i].data == NULL)
			perror_and_exit(error_map_elems);
		++i;
	}
}

void	check_sprite(t_info *new)
{
	int	i;

	binding_sprite_path(new);
	i = 0;
	while (i < ANIMATION_SIZE)
	{
		new->sprite.source[i].img = mlx_xpm_file_to_image(new->canvas->mlx,
				new->sprite.source[i].path, &new->sprite.source[i].width,
				&new->sprite.source[i].height);
		if (new->sprite.source[i].img == NULL)
			perror_and_exit(error_map_elems);
		new->sprite.source[i].data
			= mlx_get_data_addr(new->sprite.source[i].img,
				&new->sprite.source[i].bits_per_pixel,
				&new->sprite.source[i].size_line,
				&new->sprite.source[i].endian);
		if (new->sprite.source[i].data == NULL)
			perror_and_exit(error_map_elems);
		++i;
	}
}

static void	check_invalid(t_info *info, t_vector2 next_pos)
{
	if (info->map[(int)next_pos.y][(int)next_pos.x] != '1'
		&& info->map[(int)next_pos.y][(int)next_pos.x] != ' ')
		perror_and_exit(error_map_elems);
}

static void	dfs(t_info *info, t_vector2 cur_pos, t_stack *stack)
{
	t_vector2	next_pos;
	const int	direction[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	int			i;

	push(stack, cur_pos);
	info->map[(int)cur_pos.y][(int)cur_pos.x] = 'X';
	while (stack->size > 0)
	{
		cur_pos = pop(stack);
		i = -1;
		while (++i < 4)
		{
			next_pos = (t_vector2){cur_pos.x + direction[i][1],
				cur_pos.y + direction[i][0]};
			if (next_pos.x < 0 || next_pos.y < 0
				|| next_pos.x >= info->width || next_pos.y >= info->height
				|| info->map[(int)next_pos.y][(int)next_pos.x] == '1'
				|| info->map[(int)next_pos.y][(int)next_pos.x] == 'X')
				continue ;
			check_invalid(info, next_pos);
			push(stack, next_pos);
			info->map[(int)next_pos.y][(int)next_pos.x] = 'X';
		}
	}
	destroy_stack(&stack);
}

void	check_surrounded(t_info *info)
{
	t_vector2	cur_pos;

	cur_pos.y = 0;
	while (cur_pos.y < info->height)
	{
		cur_pos.x = 0;
		while (cur_pos.x < info->width)
		{
			if (info->map[(int)cur_pos.y][(int)cur_pos.x] == ' ')
				dfs(info, cur_pos, init_stack());
			++cur_pos.x;
		}
		++cur_pos.y;
	}
}
