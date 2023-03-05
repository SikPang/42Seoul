/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_man.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:58:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 20:20:47 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../info.h"
# include "../data_structure/list.h"

# define COLOR_RED 0xFF0000
# define COLOR_ORANGE 0xFF7F00
# define COLOR_YELLOW 0xFFFF00
# define COLOR_GREEN 0xFF00
# define COLOR_BLUE 0xFF
# define COLOR_NAVY 0x000080
# define COLOR_PURPLE 0x8B00FF
# define COLOR_WHITE 0xFFFFFF

# define PI 3.141592
# define EPSILON 0.9

typedef struct s_point
{
	double	dx;
	double	dy;
	double	gradient;
	double	p;
	double	distance;
	int		dx_sign;
	int		dy_sign;
	int		gradient_sign;
}	t_point;

void	put_pixel(t_mlx *mlx, int x, int y, int color);
int		get_color(t_node *p1, t_node *p2, t_point *info);
void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	draw_map(t_mlx *mlx);

#endif