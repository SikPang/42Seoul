/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:23 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/19 13:32:19 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	get_texture_num(t_dda_info *dda)
{
	if (dda->target == DOOR_SIDE + '0')
		return (DOOR_SIDE);
	else if (dda->target == DOOR_CLOSED + '0')
		return (DOOR_CLOSED);
	if (dda->hit_x == TRUE)
	{
		if (dda->step.y > 0)
			return (NORTH);
		return (SOUTH);
	}
	else
	{
		if (dda->step.x > 0)
			return (WEST);
		return (EAST);
	}
}

int	get_pixel(t_texture *texture, int x, int y)
{
	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (BUFFER_OVERFLOW);
	return (*(int *)(texture->data
		+ (texture->size_line * y + x * texture->bits_per_pixel / 8)));
}

int	get_tex_x(t_info *info, t_dda_info *dda, t_texture *texture)
{
	int		tex_x;
	float	wall_x;

	if (!dda->hit_x)
		wall_x = info->player.y + dda->perp_wall_dist * dda->ray.y;
	else
		wall_x = info->player.x + dda->perp_wall_dist * dda->ray.x;
	wall_x -= floorf(wall_x);
	tex_x = wall_x * (float)texture->width;
	if ((!dda->hit_x && dda->ray.x > 0) || (dda->hit_x && dda->ray.y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}
