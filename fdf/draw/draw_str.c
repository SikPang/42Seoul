/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:21:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 20:32:51 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "draw.h"

#include <stdio.h>
void	draw_str(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, COLOR_WHITE, "pos x : ");
	mlx_string_put(mlx->mlx, mlx->win, 20, 50, COLOR_WHITE, "pos y : ");
	mlx_string_put(mlx->mlx, mlx->win, 20, 80, COLOR_WHITE, "euler x : ");
	mlx_string_put(mlx->mlx, mlx->win, 20, 110, COLOR_WHITE, "euler x : ");
	mlx_string_put(mlx->mlx, mlx->win, 20, 140, COLOR_WHITE, "euler z : ");
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, COLOR_WHITE, "zoom : ");
}