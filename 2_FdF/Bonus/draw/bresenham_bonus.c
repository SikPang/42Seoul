/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:08:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 20:11:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "draw_bonus.h"

static int	is_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info)
{
	info->p = 2 * fabs(info->dy) - fabs(info->dx);
	while (1)
	{
		if (is_equal(p1->x, p2->x) && is_equal(p1->y, p2->y))
			break ;
		put_pixel(mlx, p1->x, p1->y, get_color(p1, p2, info));
		p1->x += 1 * info->dx_sign;
		if (info->p < 0)
			info->p += 2 * fabs(info->dy);
		else
		{
			p1->y += 1 * info->dy_sign;
			info->p += 2 * (fabs(info->dy) - fabs(info->dx));
		}
	}
}

void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info)
{
	info->p = 2 * fabs(info->dx) - fabs(info->dy);
	while (1)
	{
		if (is_equal(p1->x, p2->x) && is_equal(p1->y, p2->y))
			break ;
		put_pixel(mlx, p1->x, p1->y, get_color(p1, p2, info));
		p1->y += 1 * info->dy_sign;
		if (info->p < 0)
			info->p += 2 * fabs(info->dx);
		else
		{
			p1->x += 1 * info->dx_sign;
			info->p += 2 * (fabs(info->dx) - fabs(info->dy));
		}
	}
}
