/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:05:46 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 14:10:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	init_vectors(t_info *info)
{
	const char	dir_char[] = {'N', 'E', 'S', 'W'};
	const int	direction[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	int			idx;

	idx = -1;
	while (++idx < 4)
	{
		if (info->map[(int)info->player.y][(int)info->player.x]
			== dir_char[idx])
			break ;
	}
	info->dir.x = direction[idx][0];
	info->dir.y = direction[idx][1];
	if (idx == 0)
		idx = 4;
	info->plane.x = direction[idx - 1][0] * FOV;
	info->plane.y = direction[idx - 1][1] * FOV;
}

static t_draw	init_draw(t_info *info, t_dda_info *dda, t_texture *texture)
{
	t_draw	draw;

	draw.line_height = (float)WIN_HEIGHT / dda->perp_wall_dist * 1.2;
	draw.line_start = (float)WIN_HEIGHT / 2.f - (float)(draw.line_height) / 2.f;
	draw.line_end = (float)WIN_HEIGHT / 2.f + (float)(draw.line_height) / 2.f;
	draw.texture_pos = (t_vector2){get_tex_x(info, dda, texture), 0};
	draw.texture_step = (float)texture->height / (float)(draw.line_height);
	draw.pos = min(draw.line_start, 0);
	return (draw);
}

static void	draw_vertical_line(t_info *info, t_dda_info *dda, int i)
{
	t_texture	texture;
	t_draw		draw;

	texture = info->textures[get_texture_num(dda)];
	draw = init_draw(info, dda, &texture);
	while (draw.pos < WIN_HEIGHT)
	{
		if (draw.pos >= 0 && draw.pos < draw.line_start)
			info->canvas->draw_pixel(info->canvas,
				WIN_WIDTH - 1 - i, draw.pos, info->c_color);
		else if (draw.pos >= draw.line_start
			&& draw.pos < min(draw.line_end, WIN_HEIGHT))
		{
			if (draw.pos >= 0)
				info->canvas->draw_pixel(info->canvas, WIN_WIDTH - 1 - i,
					draw.pos, get_pixel(&texture, texture.width - 1
						- draw.texture_pos.x, draw.texture_pos.y));
			draw.texture_pos.y += draw.texture_step;
		}
		else if (draw.pos >= draw.line_end)
			info->canvas->draw_pixel(info->canvas,
				WIN_WIDTH - 1 - i, draw.pos, info->f_color);
		++draw.pos;
	}
}

void	draw(t_info *info)
{
	t_vector2	ray;
	t_dda_info	*dda;
	float		normalized_ratio;
	int			i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		normalized_ratio = 2.f * (float)i / (float)WIN_WIDTH - 1.f;
		ray.x = info->dir.x + (info->plane.x * normalized_ratio);
		ray.y = info->dir.y + (info->plane.y * normalized_ratio);
		dda = raycasting(info, ray);
		draw_vertical_line(info, dda, i);
		info->z_buffer[i] = dda->perp_wall_dist;
		free(dda);
	}
	casting_sprite(info, info->sprite_list->head);
	render_minimap(info);
	info->canvas->show(info->canvas);
}
