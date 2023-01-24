/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:50:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 22:20:47 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char    *pixel;

    pixel = mlx->addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	draw_line(t_node *p1, t_node *p2, t_mlx *mlx)
{
	double gradient;
	
	gradient = (p2->y - p1->y) / (p2->x - p1->x);
	if (gradient <= 1)
		bresenham_small(p1, p2, mlx);
	else
		bresenham_big(p1, p2, mlx);
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
