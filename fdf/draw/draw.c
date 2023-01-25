/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:50:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/25 22:25:56 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "draw.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char    *pixel;

    pixel = mlx->addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}

// y axis 45 degree	(x, y)
// x axis 35.265 degree (y, z)
// degree to radian = degree * ( pi / 180 )
// x' = x * cos(th) - y * sin(th)
// y' = x * sin(th) + y * cos(th)

#include <stdio.h>
void	isometric_projection(t_node *p)
{
	double	prev_x;

	prev_x = p->x;
	//printf("before: %f %f\n", p->x, p->y);
	p->x = p->x * cos(45.0 * PI / 180.0) - p->y * sin(45.0 * PI / 180.0) + START_POS;
	p->y = prev_x * sin(45.0 * PI / 180.0) + p->y * cos(45.0 * PI / 180.0) + START_POS;
	//printf("after: %f %f\n\n", p->x, p->y);
	//p->y = p->y * sin(35.3 * PI / 180.0) - p->z * cos(35.3 * PI / 180.0);	
}

void	draw_line(t_node *p1, t_node *p2, t_mlx *mlx)
{
	t_node	*temp1;
	t_node	*temp2;
	double	gradient;

	temp1 = copy_node(p1);
	temp2 = copy_node(p2);
	isometric_projection(temp1);
	isometric_projection(temp2);
	if (temp1->x < 0 || temp1->y < 0 || temp2->x < 0 || temp2->y < 0)
		return ;
	gradient = (temp2->y - temp1->y) / (temp2->x - temp1->x);
	//printf("%f ", gradient);
	if (gradient > 0 && gradient <= 1)
		bresenham_small(temp1, temp2, mlx);
	else if (gradient > -1)
		bresenham_big_minus(temp1, temp2, mlx);
	else if (gradient > 1)
		bresenham_big(temp1, temp2, mlx);
	else
		bresenham_small_minus(temp1, temp2, mlx);
	free(temp1);
	free(temp2);
}

void	draw_map(t_llist *map, t_mlx *mlx)
{
	t_lnode	*lnode;
	t_node	*node;
	t_node	*next_low_node;

	lnode = map->head;
	while (lnode->next_node != 0)
	{
		node = lnode->data->head;
		next_low_node = lnode->next_node->data->head;
		while (node->next_node != 0)
		{
			draw_line(node, node->next_node, mlx);
			draw_line(node, next_low_node, mlx);
			node = node->next_node;
			next_low_node = next_low_node->next_node;
		}
		draw_line(node, next_low_node, mlx);
		lnode = lnode->next_node;
	}
	node = lnode->data->head;
	while (node->next_node != 0)
	{
		draw_line(node, node->next_node, mlx);
		node = node->next_node;
	}
}
