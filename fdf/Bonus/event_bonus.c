/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:09:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/01 16:08:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "info_bonus.h"

static void	zoom_map(int key, t_mlx *mlx)
{
	if ((key == KEY_PLUS && mlx->tile_size == INT_MAX)
		|| (key == KEY_MINUS && mlx->tile_size == 0))
		return ;
	if (key == KEY_PLUS)
		mlx->tile_size += 1;
	else
		mlx->tile_size -= 1;
	update_window(mlx);
}

static void	rotate_map(int key, t_mlx *mlx)
{
	if ((key == KEY_W && mlx->euler_x == INT_MAX)
		|| (key == KEY_S && mlx->euler_x == INT_MIN)
		|| (key == KEY_A && mlx->euler_z == INT_MAX)
		|| (key == KEY_D && mlx->euler_z == INT_MIN))
		return ;
	if (key == KEY_W)
		mlx->euler_x += 1;
	else if (key == KEY_S)
		mlx->euler_x -= 1;
	else if (key == KEY_A)
		mlx->euler_z += 1;
	else
		mlx->euler_z -= 1;
	update_window(mlx);
}

static void	translate_map(int key, t_mlx *mlx)
{
	if ((key == KEY_UP && mlx->start_y == -1000)
		|| (key == KEY_DOWN && mlx->start_y == 2000)
		|| (key == KEY_LEFT && mlx->start_x == -1000)
		|| (key == KEY_RIGHT && mlx->start_x == 2000))
		return ;
	if (key == KEY_UP)
		mlx->start_y -= 5;
	else if (key == KEY_DOWN)
		mlx->start_y += 5;
	else if (key == KEY_LEFT)
		mlx->start_x -= 5;
	else
		mlx->start_x += 5;
	update_window(mlx);
}

int	press_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(1);
	else if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_DOWN)
		translate_map(key, mlx);
	else if (key == KEY_W || key == KEY_A
		|| key == KEY_S || key == KEY_D)
		rotate_map(key, mlx);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		zoom_map(key, mlx);
	else if (key == KEY_1)
		set_default(mlx);
	else if (key == KEY_2)
		to_orthogonal_z(mlx);
	else if (key == KEY_3)
		to_orthogonal_y(mlx);
	return (0);
}

int	button_exit(void)
{
	exit(1);
	return (0);
}
