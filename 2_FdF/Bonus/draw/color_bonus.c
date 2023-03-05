/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:35:43 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 21:24:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw_bonus.h"

static int	lerp(int p1_color, int p2_color, double percent)
{
	return ((1 - percent) * p1_color + percent * p2_color);
}

static int	get_value(int color, char target)
{
	int	result;

	if (target == 'R')
		result = color & ((int)255 << 16);
	else if (target == 'G')
		result = color & ((int)255 << 8);
	else if (target == 'B')
		result = color & ((int)255);
	else
		result = color & ((int)255 << 24);
	return (result);
}

static int	color_lerp(t_node *p1, t_node *p2, double percent)
{
	int	result;
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = lerp(get_value(p1->color, 'R'), get_value(p2->color, 'R'), percent);
	green = lerp(get_value(p1->color, 'G'), get_value(p2->color, 'G'), percent);
	blue = lerp(get_value(p1->color, 'B'), get_value(p2->color, 'B'), percent);
	alpha = lerp(get_value(p1->color, 'A'), get_value(p2->color, 'A'), percent);
	result = red | green | blue | alpha;
	return (result);
}

int	get_color(t_node *p1, t_node *p2, t_point *info)
{
	double	distance;
	double	percent;
	int		color;

	if (p1->color == p2->color)
		return (p1->color);
	distance = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
	percent = 1 - distance / info->distance;
	color = color_lerp(p1, p2, percent);
	return (color);
}
