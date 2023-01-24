/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:58:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 22:22:19 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../info.h"
# include "../data_structure/list.h"

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0xFF00
# define COLOR_WHITE 0xFFFFFF

void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx);
void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	draw_map(t_llist *map, t_mlx *mlx);

#endif