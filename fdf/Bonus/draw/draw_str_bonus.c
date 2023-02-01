/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:21:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/01 16:13:53 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "draw_bonus.h"
#include "../utility/utility_bonus.h"

static void	put_str(char *str, char *num, t_mlx *mlx, int pos)
{
	mlx_string_put(mlx->mlx, mlx->win, 20, 20 + pos, COLOR_WHITE, str);
	mlx_string_put(mlx->mlx, mlx->win, 120, 20 + pos, COLOR_WHITE, num);
	free(num);
}

void	draw_str(t_mlx *mlx)
{
	put_str("pos x : ", ft_itoa(mlx->start_x), mlx, 0);
	put_str("pos y : ", ft_itoa(mlx->start_y), mlx, 30);
	put_str("euler x : ", ft_itoa(mlx->euler_x), mlx, 60);
	put_str("euler z : ", ft_itoa(mlx->euler_z), mlx, 90);
	put_str("zoom : ", ft_itoa(mlx->tile_size), mlx, 120);
}
