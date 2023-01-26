/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:35:43 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/26 22:36:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	get_color(t_node *p1, t_node *p2)
{
	if (p1->z > 0 && p2->z > 0)
		return (COLOR_RED);
	else if (p1->z < 0 && p2->z < 0)
		return (COLOR_GREEN);
	else
		return (COLOR_WHITE);
}
