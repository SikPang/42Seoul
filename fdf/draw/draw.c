/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:50:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 17:41:01 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "draw.h"

static t_point	*get_info_between_points(t_node *p1, t_node *p2)
{
	t_point	*info;

	info = (t_point *)malloc(sizeof(t_point));
	info->dx = p2->x - p1->x;
	info->dy = p2->y - p1->y;
	info->gradient = info->dy / info->dx;
	info->distance = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
	if (info->dx >= 0)
		info->dx_sign = 1;
	else
		info->dx_sign = -1;
	if (info->dy >= 0)
		info->dy_sign = 1;
	else
		info->dy_sign = -1;
	if (info->gradient >= 0)
		info->gradient_sign = 1;
	else
		info->gradient_sign = -1;
	return (info);
}

// y axis 45 degree	(x, y)
// x axis 35.265 degree (y, z)
// degree to radian = degree * ( pi / 180 )
// x' = x * cos(th) - y * sin(th)
// y' = x * sin(th) + y * cos(th)

static void	isometric_projection(t_node *p, t_mlx *mlx)
{
	double	prev_x;

	prev_x = p->x;
	p->x = p->x * cos(45.0 * PI / 180.0) - p->y * sin(45.0 * PI / 180.0);
	p->y = prev_x * sin(45.0 * PI / 180.0) + p->y * cos(45.0 * PI / 180.0);
	p->y = p->y * cos(35.3 * PI / 180.0) - p->z * sin(35.3 * PI / 180.0);
	p->x += mlx->start_pos;
	p->y += mlx->start_pos / 2;	
}

static void	draw_line(t_node *p1, t_node *p2, t_mlx *mlx)
{
	t_node	*temp1;
	t_node	*temp2;
	t_point	*info;

	temp1 = copy_node(p1);
	temp2 = copy_node(p2);
	isometric_projection(temp1, mlx);
	isometric_projection(temp2, mlx);
	if (temp1->x < 0 || temp1->y < 0 || temp2->x < 0 || temp2->y < 0
		|| temp1->x > WIN_WIDTH || temp1->y > WIN_HEIGHT
		|| temp2->x > WIN_WIDTH || temp2->y > WIN_HEIGHT)
		return ;
	info = get_info_between_points(temp1, temp2);
	if (fabs(info->gradient) <= 1)
		bresenham_small(temp1, temp2, mlx, info);
	else
		bresenham_big(temp1, temp2, mlx, info);
	free(temp1);
	free(temp2);
	free(info);
}

void	draw_map(t_mlx *mlx)
{
	t_lnode	*lnode;
	t_node	*node;
	t_node	*next_low_node;

	lnode = mlx->map->head;
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
