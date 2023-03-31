/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_observe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:32:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 22:22:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*observing(void *data)
{
	t_info	*info;

	info = (t_info *)data;
	while (1)
	{
		if (info->philo.starving_time >= info->time_to_die)
		{
			philo_print(info, DIED);
			exit(44);
		}
		info->philo.starving_time += 10;
		usleep(1000 * 10);
	}
	return (data);
}
