/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:21:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 22:18:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "draw.h"
#include "../utility/utility.h"

#include <stdio.h>
void	draw_str(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, COLOR_WHITE, "pos x : ");
	mlx_string_put(mlx->mlx, mlx->win, 100, 20, COLOR_WHITE, ft_itoa(mlx->start_x));
	mlx_string_put(mlx->mlx, mlx->win, 20, 50, COLOR_WHITE, "pos y : ");
	mlx_string_put(mlx->mlx, mlx->win, 100, 50, COLOR_WHITE, ft_itoa(mlx->start_y));
	mlx_string_put(mlx->mlx, mlx->win, 20, 80, COLOR_WHITE, "euler x : ");
	mlx_string_put(mlx->mlx, mlx->win, 130, 80, COLOR_WHITE, ft_itoa(mlx->euler_x));
	mlx_string_put(mlx->mlx, mlx->win, 20, 110, COLOR_WHITE, "euler z : ");
	mlx_string_put(mlx->mlx, mlx->win, 130, 110, COLOR_WHITE, ft_itoa(mlx->euler_z));
	mlx_string_put(mlx->mlx, mlx->win, 20, 140, COLOR_WHITE, "zoom : ");
	mlx_string_put(mlx->mlx, mlx->win, 100, 140, COLOR_WHITE, ft_itoa(mlx->tile_size));
}