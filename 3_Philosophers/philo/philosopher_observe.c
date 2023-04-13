/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_observe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:49:11 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/12 11:43:15 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mutex/access_mutex.h"
#include "philosopher.h"

_Bool	philo_usleep(t_philo *philo, long start_time, int time_for_wait)
{
	while (get_time_from(&(philo->info->start_time)) - start_time
		< time_for_wait)
	{
		if (check_dead(philo) == TRUE)
			return (FALSE);
		usleep(CHECK_CYCLE);
	}
	return (TRUE);
}

void	observing(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->info->max_philo)
		{
			if (check_dead(philo) == TRUE
				|| check_starve(philo + i) == TRUE)
				return ;
			++i;
		}
		if (check_done(philo) == TRUE)
			return ;
		usleep(OBSERVE_CYCLE);
	}
}
