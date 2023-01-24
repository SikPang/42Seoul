/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:50:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 20:03:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "utility/utility.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char    *pixel;

    pixel = mlx->addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	draw_line()
{

}
