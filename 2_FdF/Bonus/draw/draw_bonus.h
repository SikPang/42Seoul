/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:58:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 20:22:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H

# include "../info_bonus.h"
# include "../data_structure/list_bonus.h"

# define COLOR_RED 0xFF0000
# define COLOR_ORANGE 0xFF7F00
# define COLOR_YELLOW 0xFFFF00
# define COLOR_GREEN 0xFF00
# define COLOR_BLUE 0xFF
# define COLOR_NAVY 0x000080
# define COLOR_PURPLE 0x8B00FF
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x0

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

void	draw_str(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	clear_window(t_mlx *mlx);
int		get_color(t_node *p1, t_node *p2, t_point *info);
void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	draw_map(t_mlx *mlx);

#endif