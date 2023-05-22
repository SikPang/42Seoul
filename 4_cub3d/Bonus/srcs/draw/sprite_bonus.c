/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:50:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 15:40:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"

static void	sort_sprites(t_info *info)
{
	t_node		*cur_out;
	t_node		*cur_in;
	t_vector2	temp;

	cur_out = info->sprite_list->head;
	while (cur_out != NULL && cur_out->next != NULL)
	{
		cur_in = cur_out;
		while (cur_in != NULL && cur_in->next != NULL)
		{
			if (get_distance(info->player, cur_in->data.vec)
				< get_distance(info->player, cur_in->next->data.vec))
			{
				temp = cur_in->data.vec;
				cur_in->data.vec = cur_in->next->data.vec;
				cur_in->next->data.vec = temp;
			}
			cur_in = cur_in->next;
		}
		cur_out = cur_out->next;
	}
}

static t_vector2	get_transform(t_info *info, t_node *cur)
{
	t_vector2	pos_rl;
	t_vector2	trans;
	float		inv_det;

	pos_rl.x = cur->data.vec.x - info->player.x;
	pos_rl.y = cur->data.vec.y - info->player.y;
	inv_det = 1.0 / (info->plane.x * info->dir.y - info->dir.x * info->plane.y);
	trans.x = inv_det * (info->dir.y * pos_rl.x - info->dir.x * pos_rl.y);
	trans.y = inv_det * (-info->plane.y * pos_rl.x + info->plane.x * pos_rl.y);
	return (trans);
}

static void	draw_sprite_vertical_line(t_info *info, t_vector2 trans,
	int x, int tex_x)
{
	int	v_move_screen;
	int	sprite_screen_height;
	int	end;
	int	color;
	int	y;

	v_move_screen = (int)(V_MOVE / trans.y);
	sprite_screen_height = (int)fabs(WIN_HEIGHT / trans.y);
	y = max(0, -sprite_screen_height / 2.f + WIN_HEIGHT / 2.f + v_move_screen);
	end = min(WIN_HEIGHT, sprite_screen_height / 2.f + WIN_HEIGHT / 2.f
			+ v_move_screen);
	while (y < end)
	{
		color = get_pixel(info->sprite.cur, info->sprite.cur->width - 1 - tex_x,
				(y - v_move_screen - WIN_HEIGHT / 2.f)
				* info->sprite.cur->height / (float)sprite_screen_height
				+ info->sprite.cur->height / 2.f);
		if (!(color >> 24))
			info->canvas->draw_pixel(info->canvas, WIN_WIDTH - 1 - x, y, color);
		++y;
	}
}

void	casting_sprite(t_info *info, t_node *cur)
{
	t_vector2	trans;
	int			sprite_screen_x;
	int			sprite_screen_width;
	int			x;
	int			end;

	sort_sprites(info);
	while (cur != NULL)
	{
		trans = get_transform(info, cur);
		sprite_screen_x = (WIN_WIDTH / 2.f) * (1.f + trans.x / trans.y);
		sprite_screen_width = (int)fabs(WIN_HEIGHT / trans.y
				/ sqrtf(powf(info->plane.x, 2) + powf(info->plane.y, 2)));
		x = max(0, -sprite_screen_width / 2 + sprite_screen_x);
		end = min(WIN_WIDTH, sprite_screen_width / 2 + sprite_screen_x);
		while (x < end)
		{
			if (trans.y > 0 && trans.y < info->z_buffer[x])
				draw_sprite_vertical_line(info, trans, x, (x - sprite_screen_x)
					* info->sprite.cur->width / (float)sprite_screen_width
					+ info->sprite.cur->width / 2.f);
			++x;
		}
		cur = cur->next;
	}
}
