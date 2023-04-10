/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_observe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:32:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 13:31:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*observing(void *data)
{
	t_info	*info;
	int		last_eat;

	info = (t_info *)data;
	while (1)
	{
		sem_wait(info->starve[info->philo.my_number - 1]);
		last_eat = info->philo.time_last_eat;
		sem_post(info->starve[info->philo.my_number - 1]);
		if (get_time_from(&(info->start_time)) - last_eat >= info->time_to_die)
		{
			philo_print(info, DIED);
			exit(DEATH_SIGNAL);
		}
		usleep(OBSERVE_CYCLE);
	}
	return (data);
}
