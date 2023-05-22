/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:28:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 14:00:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <math.h>

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

int			max(int a, int b);
int			min(int a, int b);
float		to_radian(float degree);
t_vector2	rotate_matrix(t_vector2 cur_vec, float radian);
float		get_distance(t_vector2 a, t_vector2 b);

#endif