/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:58:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/29 21:26:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../info.h"
# include "../data_structure/list.h"

# define COLOR_RED 0x00FF0000
# define COLOR_GREEN 0x0000FF00
# define COLOR_WHITE 0x00FFFFFF

#define PI 3.141592
#define EPSILON 0.99

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

int		get_color(t_node *p1, t_node *p2, t_point *info);
void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx, t_point *info);
void	draw_map(t_llist *map, t_mlx *mlx);

#endif