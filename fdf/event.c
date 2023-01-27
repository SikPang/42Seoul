/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:09:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/25 17:15:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "info.h"

int	press_key(int key_code)
{
	if (key_code == KEY_ESC)
		exit(1);
}

int	button_exit(int key_code)
{
	exit(1);
}