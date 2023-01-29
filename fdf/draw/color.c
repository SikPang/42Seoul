/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:35:43 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/29 22:40:19 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw.h"

#include <stdio.h>
static unsigned int	lerp(unsigned int p1_color, unsigned int p2_color, double percent)
{
	return ((1 - percent) * p1_color + percent * p2_color);
}

static unsigned int	get_value(unsigned int color, char target)
{
	unsigned int	result;
	
	if (target == 'R')
		result = color & ((unsigned int)255 << 16);
	else if (target == 'G')
		result = color & ((unsigned int)255 << 8);
	else if (target == 'B')
		result = color & ((unsigned int)255);
	else
		result = color & ((unsigned int)255 << 24);
	return (result);
}

static unsigned int	color_lerp(t_node *p1, t_node *p2, double percent)
{
	unsigned int	result;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	alpha;
	
	red = lerp(get_value(p1->color, 'R'), get_value(p2->color, 'R'), percent);
	green = lerp(get_value(p1->color, 'G'), get_value(p2->color, 'G'), percent);
	blue = lerp(get_value(p1->color, 'B'), get_value(p2->color, 'B'), percent);
	alpha = lerp(get_value(p1->color, 'A'), get_value(p2->color, 'A'), percent);
	result = red | green | blue | alpha;
	return (result);
}

int	get_color(t_node *p1, t_node *p2, t_point *info)
{
	// 두개의 색깔 사이의 값을 거리에 따라 반환
	// 현재 지나온 거리 (%) 필요
	// 현재 좌표를 %로 바꾸기
	double			distance;
	double			percent;
	unsigned int	color;

	if (p1->color == p2->color)
		return (p1->color);
	distance = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
	percent = 1 - distance / info->distance;
	color = color_lerp(p1, p2, percent);
	printf("%u, %u, %u, %0.2f/%0.2f (%0.2f%%)\n", p1->color, p2->color, color, distance, info->distance, percent);
	return (color);
}

// int	get_color(t_node *p1, t_node *p2, t_point *info)
// {
// 	// 두개의 색깔 사이의 값을 거리에 따라 반환
// 	// 현재 지나온 거리 (%) 필요
// 	// 현재 좌표를 %로 바꾸기
// 	return (p1->color);
// }