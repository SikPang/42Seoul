/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:21:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 15:30:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include <stdlib.h>
# include <math.h>
# include "key_code_mac.h"
# include "info.h"
# include "draw.h"
# include "move.h"

void	move(int key, t_info *info);
int		mouse_move(int x, int y, t_info *info);
int		press_key(int key, t_info *info);
int		exit_on_event(void);

#endif
