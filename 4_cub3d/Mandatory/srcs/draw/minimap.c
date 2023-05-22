/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:21:50 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 11:28:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static int	set_color(t_info *info, t_vector2 cur)
{
	if (info->map[(int)cur.y][(int)cur.x] == '1')
		return (COLOR_GREEN);
	else if (info->map[(int)cur.y][(int)cur.x] == '0'
		|| info->map[(int)cur.y][(int)cur.x] == 'N'
		|| info->map[(int)cur.y][(int)cur.x] == 'W'
		|| info->map[(int)cur.y][(int)cur.x] == 'E'
		|| info->map[(int)cur.y][(int)cur.x] == 'S')
		return (COLOR_WHITE);
	else if (info->map[(int)cur.y][(int)cur.x] == '4'
		|| info->map[(int)cur.y][(int)cur.x] == '5')
		return (COLOR_GRAY);
	else if (info->map[(int)cur.y][(int)cur.x] == '3')
		return (COLOR_RED);
	else
		return (-1);
}

static void	big_draw(t_info *info, t_vector2 cur
	, t_vector2 start_pos, int color)
{
	int	row;
	int	col;

	row = 0;
	while (row < CUB_SIZE)
	{
		col = -1;
		while (++col < CUB_SIZE)
		{
			if (start_pos.x + col + cur.x * CUB_SIZE
				< MINIMAP_START_POS + BORDER_SIZE
				|| start_pos.x + col + cur.x * CUB_SIZE
				> MINIMAP_SIZE - BORDER_SIZE + 1
				|| start_pos.y + row + cur.y * CUB_SIZE
				< MINIMAP_START_POS + BORDER_SIZE
				|| start_pos.y + row + cur.y * CUB_SIZE
				> MINIMAP_SIZE - BORDER_SIZE + 1)
				continue ;
			info->canvas->draw_pixel(info->canvas
				, start_pos.x + col + cur.x * CUB_SIZE
				, start_pos.y + row + cur.y * CUB_SIZE
				, color);
		}
		++row;
	}
}

static void	draw_minimap(t_info *info, t_vector2 start_pos)
{
	int	row;
	int	col;
	int	color;

	row = 0;
	while (row < info->height)
	{
		col = 0;
		while (col < info->width)
		{
			color = set_color(info, (t_vector2){col, row});
			if (color != -1)
				big_draw(info, (t_vector2){col, row}, start_pos, color);
			++col;
		}
		++row;
	}
	big_draw(info, (t_vector2){info->player.x - 0.5, info->player.y - 0.5},
		start_pos, COLOR_BLUE);
}

static void	draw_background(t_info *info)
{
	int	row;
	int	col;
	int	color;

	row = MINIMAP_START_POS;
	while (row < MINIMAP_SIZE)
	{
		col = MINIMAP_START_POS;
		while (col < MINIMAP_SIZE)
		{
			if (row < MINIMAP_START_POS + BORDER_SIZE
				|| col < MINIMAP_START_POS + BORDER_SIZE
				|| row > MINIMAP_SIZE - BORDER_SIZE
				|| col > MINIMAP_SIZE - BORDER_SIZE)
				color = COLOR_YELLOW;
			else
				color = COLOR_BLACK;
			info->canvas->draw_pixel(info->canvas, col, row, color);
			++col;
		}
		++row;
	}
}

void	render_minimap(t_info *info)
{
	t_vector2	start_pos;

	start_pos.x = MINIMAP_START_POS + (CENTER - info->player.x) * CUB_SIZE;
	start_pos.y = MINIMAP_START_POS + (CENTER - info->player.y) * CUB_SIZE;
	draw_background(info);
	draw_minimap(info, start_pos);
}
