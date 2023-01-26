/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:58:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/26 22:24:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../info.h"
# include "../data_structure/list.h"

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0xFF00
# define COLOR_WHITE 0xFFFFFF

#define PI 3.141592
#define EPSILON 0.99

typedef struct s_point
{
	double	dx;
	double	dy;
	double	gradient;
	double	p;
	int		dx_sign;
	int		dy_sign;
	int		gradient_sign;
}	t_point;

t_point	*get_info_between_points(t_node *p1, t_node *p2);
void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int		get_color(t_node *p1, t_node *p2);
void	draw_map(t_llist *map, t_mlx *mlx);

#endif