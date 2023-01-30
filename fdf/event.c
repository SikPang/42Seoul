/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:09:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 21:45:03 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "info.h"

int	press_key(int key_code)
{
	if (key_code == KEY_ESC)
		exit(1);
	else if (key_code == KEY_C)	// KEY_CHANGE
		exit(1);
	else if (key_code == KEY_Z)	// KEY_ZOOM
		exit(1);
	else if (key_code == KEY_T)	// KEY_TRANSLATE
		exit(1);
	else if (key_code == KEY_R)	// KEY_ROTATE
		exit(1);
	else if (key_code == KEY_I)	// KEY_INVERT
		exit(1);
	return (0);
}

int	button_exit(int key_code)
{
	exit(1);
	return (0);
}
