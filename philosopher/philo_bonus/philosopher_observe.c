/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_observe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:32:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/04 22:18:16 by kwsong           ###   ########.fr       */
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
		sem_wait(info->starve[info->philo.my_number]);
		last_eat = info->philo.time_last_eat;
		sem_post(info->starve[info->philo.my_number]);
		if (get_time_from(&(info->start_time)) - last_eat >= info->time_to_die)
		{
			philo_print(info, DIED);
			exit(44);
		}
		usleep(600);
	}
	return (data);
}
