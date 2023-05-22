/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:28:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 14:00:48 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float	get_distance(t_vector2 a, t_vector2 b)
{
	return (powf(a.x - b.x - 0.5, 2) + powf(a.y - b.y - 0.5, 2));
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

float	to_radian(float degree)
{
	return (degree * (float)M_PI / 180.f);
}

t_vector2	rotate_matrix(t_vector2 cur_vec, float radian)
{
	t_vector2	rotated;

	rotated.x = cur_vec.x * cosf(radian) - cur_vec.y * sinf(radian);
	rotated.y = cur_vec.x * sinf(radian) + cur_vec.y * cosf(radian);
	return (rotated);
}
