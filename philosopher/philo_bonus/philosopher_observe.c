/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_observe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:32:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/04 20:58:47 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*observing(void *data)
{
	t_info	*info;

	info = (t_info *)data;
	while (1)
	{
		sem_wait(info->starve);
		if (get_time_from(&(info->start_time)) - info->philo.time_last_eat
			>= info->time_to_die)
		{
			philo_print(info, DIED);
			sem_post(info->starve);
			exit(44);
		}
		sem_post(info->starve);
		usleep(600);
	}
	return (data);
}
