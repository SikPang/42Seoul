/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:10:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 16:23:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static _Bool	is_collided(t_info *info, t_dda_info *dda)
{
	if (info->map[(int)dda->cur.y][(int)dda->cur.x] == '1'
		|| info->map[(int)dda->cur.y][(int)dda->cur.x] == '5')
		return (TRUE);
	return (FALSE);
}

void	step_to_int_pos(t_dda_info *dda)
{
	if (dda->cur_dist.x < dda->cur_dist.y)
	{
		dda->cur_dist.x += dda->interval.x;
		dda->cur.x += dda->step.x;
		dda->hit_x = FALSE;
	}
	else
	{
		dda->cur_dist.y += dda->interval.y;
		dda->cur.y += dda->step.y;
		dda->hit_x = TRUE;
	}
}

t_dda_info	*init_dda_info(t_info *info, t_vector2 ray)
{
	t_dda_info	*dda;

	dda = (t_dda_info *)malloc(sizeof(t_dda_info));
	if (dda == NULL)
		perror_and_exit(error_malloc);
	dda->ray = ray;
	dda->interval.x = sqrt(1 + (ray.y * ray.y) / (ray.x * ray.x));
	dda->interval.y = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y));
	dda->hit_x = FALSE;
	dda->perp_wall_dist = 0.f;
	dda->cur.x = (float)(int)info->player.x;
	dda->cur.y = (float)(int)info->player.y;
	dda->step.x = 1 - 2 * (ray.x < 0);
	dda->step.y = 1 - 2 * (ray.y < 0);
	if (ray.x < 0)
		dda->cur_dist.x = (info->player.x - dda->cur.x) * dda->interval.x;
	else
		dda->cur_dist.x = (dda->cur.x + 1.f - info->player.x) * dda->interval.x;
	if (ray.y < 0)
		dda->cur_dist.y = (info->player.y - dda->cur.y) * dda->interval.y;
	else
		dda->cur_dist.y = (dda->cur.y + 1.f - info->player.y) * dda->interval.y;
	return (dda);
}

static _Bool	is_wall_facing_door(t_info *info, t_dda_info *dda)
{
	int	facing_x;
	int	facing_y;

	facing_x = (int)dda->cur.x;
	facing_y = (int)dda->cur.y;
	if (dda->hit_x)
	{
		if (dda->step.y > 0)
			facing_y--;
		else
			facing_y++;
	}
	else
	{
		if (dda->step.x > 0)
			facing_x--;
		else
			facing_x++;
	}
	if (info->map[(int)dda->cur.y][(int)dda->cur.x] == '1'
		&& info->map[facing_y][facing_x] == DOOR_OPENED + '0')
		return (TRUE);
	return (FALSE);
}

t_dda_info	*raycasting(t_info *info, t_vector2 ray)
{
	t_dda_info	*dda;

	dda = init_dda_info(info, ray);
	while (1)
	{
		step_to_int_pos(dda);
		if (is_collided(info, dda))
		{
			if (is_wall_facing_door(info, dda))
				dda->target = DOOR_SIDE + '0';
			else
				dda->target = info->map[(int)dda->cur.y][(int)dda->cur.x];
			break ;
		}
	}
	if (dda->hit_x == FALSE)
		dda->perp_wall_dist
			= (dda->cur.x - info->player.x + (1 - dda->step.x) / 2) / ray.x;
	else
		dda->perp_wall_dist
			= (dda->cur.y - info->player.y + (1 - dda->step.y) / 2) / ray.y;
	dda->cur_dist.y -= dda->interval.y;
	dda->cur_dist.x -= dda->interval.x;
	return (dda);
}
