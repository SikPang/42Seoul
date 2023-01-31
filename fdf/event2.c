/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:32:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 20:01:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "info.h"
#include "draw/draw.h"

void	update_window(t_mlx *mlx)
{
	clear_window(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	set_default(t_mlx *mlx)
{
	adjust_scale_and_pos(mlx);
	update_window(mlx);
}

void	to_orthogonal_z(t_mlx *mlx)
{
	mlx->start_x = 250;
	mlx->start_y = 500;
	mlx->euler_z = 0.0;
	mlx->euler_x = 90.0;
	mlx->tile_size *= 1.25;
	update_window(mlx);
}

void	to_orthogonal_y(t_mlx *mlx)
{
	mlx->start_x = 250;
	mlx->start_y = 250;
	mlx->euler_z = 0.0;
	mlx->euler_x = 0.0;
	update_window(mlx);
}

void	invert_map(t_mlx *mlx)
{
	t_lnode	*lnode;
	t_node	*node;

	lnode = mlx->map->head;
	while (lnode != 0)
	{
		node = lnode->data->head;
		while (node != 0)
		{
			node->z *= -1;
			node = node->next_node;
		}
		lnode = lnode->next_node;
	}
	update_window(mlx);
}
