/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:09:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 17:56:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "info.h"
#include "draw/draw.h"

static void	zoom_map(int key, t_mlx *mlx)
{
	
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
}

static void	rotate_map(int key, t_mlx *mlx)
{
	
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
}

static void	translate_map(int key, t_mlx *mlx)
{
	
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
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
