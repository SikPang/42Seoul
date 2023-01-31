/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:09:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 18:20:06 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "info.h"
#include "draw/draw.h"

int	press_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(1);
	return (0);
}

int	button_exit(int key)
{
	exit(1);
	return (0);
}
