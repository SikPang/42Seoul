/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:51:58 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 11:28:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# define ROTATE_DEGREE 2.f
# define MOVE_SPEED 0.1f
# define FAT 0.15f
# define RIGHT -1
# define LEFT  1
# define DIST_DOOR_ACTION 2.f

# include "info.h"
# include "raycasting.h"
# include "key_code_mac.h"
# include "ft_math.h"

_Bool		is_collided(int key, t_info *info, t_vector2 right_dir,
				t_vector2 move_dir);
t_vector2	get_move_dir(int key, t_info *info, t_vector2 right_dir);
void		door_action(t_info *info);

#endif