/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:08:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/25 22:29:23 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include <stdio.h>

// 브레젠헴 최적화
void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx)
{
	double	cur_x;
	double	cur_y;
	double	dx;
	double	dy;
	double	p;
 
	cur_x = p1->x;
	cur_y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	p = 2 * dy - dx;
	printf("small\n");
	while (cur_x < p2->x || cur_y < p2->y)
	{
		if (p1->z > 0 && p2->z > 0)
			put_pixel(mlx, cur_x, cur_y, COLOR_RED);
		else
			put_pixel(mlx, cur_x, cur_y, COLOR_WHITE);
		cur_x += 1;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			cur_y += 1;
			p = p + 2 * (dy - dx);
		}
	}
}

void	bresenham_small_minus(t_node *p1, t_node *p2, t_mlx *mlx)
{
	double	cur_x;
	double	cur_y;
	double	dx;
	double	dy;
	double	p;
 
	cur_x = p1->x;
	cur_y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	p = 2 * dy - dx;
	printf("small_minus\n");
	//printf("%0.f/%0.f, %0.f/%0.f\n", cur_x, p2->x, cur_y, p2->y);
	while (cur_x > p2->x || cur_y < p2->y)
	{
		if (p1->z > 0 && p2->z > 0)
			put_pixel(mlx, cur_x, cur_y, COLOR_RED);
		else
			put_pixel(mlx, cur_x, cur_y, COLOR_WHITE);
		cur_x -= 1;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			cur_y += 1;
			p = p + 2 * (dy - dx);
		}
	}
}

void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx)
{
	double	cur_x;
	double	cur_y;
	double	dx;
	double	dy;
	double	p;

	cur_x = p1->x;
	cur_y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	p = 2 * dx - dy;
	printf("big\n");
	while (cur_x < p2->x || cur_y < p2->y)
	{
		if (p1->z > 0 && p2->z > 0)
			put_pixel(mlx, cur_x, cur_y, COLOR_RED);
		else
			put_pixel(mlx, cur_x, cur_y, COLOR_WHITE);
		cur_y += 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			cur_x += 1;
			p = p + 2 * (dx - dy);
		}
	}
}

void	bresenham_big_minus(t_node *p1, t_node *p2, t_mlx *mlx)
{
	double	cur_x;
	double	cur_y;
	double	dx;
	double	dy;
	double	p;

	cur_x = p1->x;
	cur_y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	p = 2 * dx - dy;
	printf("big_minus\n");
	while (cur_x < p2->x || cur_y > p2->y)
	{
		if (p1->z > 0 && p2->z > 0)
			put_pixel(mlx, cur_x, cur_y, COLOR_RED);
		else
			put_pixel(mlx, cur_x, cur_y, COLOR_WHITE);
		cur_y -= 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			cur_x += 1;
			p = p + 2 * (dx - dy);
		}
	}
}
