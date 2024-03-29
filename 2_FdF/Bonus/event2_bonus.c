/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:32:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/01 16:41:08 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "info_bonus.h"
#include "draw/draw_bonus.h"

void	update_window(t_mlx *mlx)
{
	clear_window(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	draw_str(mlx);
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
