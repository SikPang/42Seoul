/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:56:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 15:04:32 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame.h"

int	frame(t_info *info)
{
	if (info->frame_count % ANIMATION_INTERVAL == 0)
	{
		info->sprite.cur = &info->sprite.source[info->sprite.count];
		++info->sprite.count;
		info->sprite.count %= ANIMATION_SIZE;
		info->frame_count = 0;
	}
	if (info->frame_count % RENDER_INTERVAL == 0)
		draw(info);
	++info->frame_count;
	return (0);
}
