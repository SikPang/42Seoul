/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:09:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 18:38:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "info.h"
#include "draw/draw.h"

#include <stdio.h>
static void	zoom_map(int key, t_mlx *mlx)
{
	if (key == KEY_PLUS)
		mlx->tile_size += 1;
	else
		mlx->tile_size -= 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

static void	rotate_map(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->euler_x += 1;
	else if (key == KEY_S)
		mlx->euler_x -= 1;
	else if (key == KEY_A)
		mlx->euler_z += 1;
	else
		mlx->euler_z -= 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

static void	translate_map(int key, t_mlx *mlx)
{
	if (key == KEY_UP)
		mlx->start_y -= 1;
	else if (key == KEY_DOWN)
		mlx->start_y += 1;
	else if (key == KEY_LEFT)
		mlx->start_x -= 1;
	else
		mlx->start_x += 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int	press_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(1);
	else if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_DOWN)	// Translate
		translate_map(key, mlx);
	else if (key == KEY_W || key == KEY_A
		|| key == KEY_S || key == KEY_D)	// Rotate
		rotate_map(key, mlx);
	else if (key == KEY_PLUS || key == KEY_MINUS)	// Zoom
		zoom_map(key, mlx);
	else if (key == KEY_1)	// Isometric
		exit(1);
	else if (key == KEY_2)	// Another
		exit(1);
	else if (key == KEY_3)	// Invert
		exit(1);
	return (0);
}

int	button_exit(int key)
{
	exit(1);
	return (0);
}
