/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:08:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/26 19:06:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "draw.h"

#include <stdio.h>
void	bresenham_small(t_node *p1, t_node *p2, t_mlx *mlx, int check)
{
	t_node	*cur;
	double	dx;
	double	dy;
	double	p;
	
	cur = copy_node(p1);
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	p = 2 * dy - dx;
	printf("small : %d\n", check);
	while (1)
	{
		if ((check > 0 && cur->x >= p2->x && cur->y >= p2->y)
			|| (check < 0 && cur->x <= p2->x && cur->y >= p2->y))
			break ;
		put_pixel(mlx, cur->x, cur->y, get_color(p1, p2));
		cur->x += 1 * check;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			cur->y += 1;
			p = p + 2 * (dy - dx);
		}
	}
	free(cur);
}

void	bresenham_big(t_node *p1, t_node *p2, t_mlx *mlx, int check)
{
	t_node	*cur;
	double	dx;
	double	dy;
	double	p;
	
	cur = copy_node(p1);
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	p = 2 * dx - dy;
	printf("big : %d\n", check);
	//printf("%0.f/%0.f, %0.f/%0.f\n", cur->x, p2->x, cur->y, p2->y);
	while (1)
	{
		if ((check > 0 && cur->x >= p2->x && cur->y >= p2->y)
			|| (check < 0 && cur->x >= p2->x && cur->y <= p2->y))
			break ;
		put_pixel(mlx, cur->x, cur->y, get_color(p1, p2));
		cur->y += 1 * check;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			cur->x += 1;
			p = p + 2 * (dx - dy);
		}
	}
	free(cur);
}
