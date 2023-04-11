/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_observe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:49:11 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 16:27:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mutex/access_mutex.h"
#include "philosopher.h"

void	observing(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->info->max_philo)
		{
			if (check_dead(philo) == TRUE
				|| check_starve(philo) == TRUE)
				return ;
			++i;
		}
		if (check_done(philo) == TRUE)
			return ;
		usleep(OBSERVE_CYCLE);
	}
}
