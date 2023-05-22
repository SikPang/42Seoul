/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:57:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 15:07:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_BONUS_H
# define FRAME_BONUS_H

# include "info_bonus.h"
# include "draw_bonus.h"

# define RENDER_INTERVAL 10
# define ANIMATION_INTERVAL 100

int	frame(t_info *info);

#endif