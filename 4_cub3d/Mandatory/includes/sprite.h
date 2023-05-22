/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:03:14 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 14:10:17 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# define V_MOVE 130.0

# include "info.h"
# include "draw.h"
# include "ft_math.h"

void	casting_sprite(t_info *info, t_node *cur);

#endif