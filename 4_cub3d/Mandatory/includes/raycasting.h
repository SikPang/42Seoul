/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:10:17 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 16:23:51 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "info.h"
# include "ft_math.h"

typedef struct s_dda_info
{
	t_vector2	cur;
	t_vector2	cur_dist;
	t_vector2	interval;
	t_vector2	step;
	t_vector2	ray;
	float		perp_wall_dist;
	_Bool		hit_x;
	char		target;
}	t_dda_info;

t_dda_info	*init_dda_info(t_info *info, t_vector2 ray);
t_dda_info	*raycasting(t_info *info, t_vector2 ray);

#endif