/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_observe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:49:11 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 15:19:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

_Bool	check_fork(t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	if (fork->is_available)
	{
		fork->is_available = FALSE;
		pthread_mutex_unlock(&(fork->mutex));
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(&(fork->mutex));
		return (FALSE);
	}
}

void	put_down_fork(t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	fork->is_available = TRUE;
	pthread_mutex_unlock(&(fork->mutex));
}

_Bool	check_done(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->done));
	if (philo->info->is_done == TRUE)
	{
		pthread_mutex_unlock(&(philo->info->done));
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(&(philo->info->done));
		return (FALSE);
	}
}

void	set_done(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->done));
	philo->info->is_done = TRUE;
	pthread_mutex_unlock(&(philo->info->done));
}

void	observing(t_philo *philo)
{
	long	cur_time;
	int		last_eat;
	int		i;

	while (1)
	{
		cur_time = get_time_from(&(philo->info->start_time));
		i = 0;
		while (i < philo->info->max_philo)
		{
			if (check_done(philo) == TRUE)
				return ;
			pthread_mutex_lock(&(philo->starve));
			last_eat = philo->time_last_eat;
			pthread_mutex_unlock(&(philo->starve));
			if (cur_time - last_eat >= philo->info->time_to_die)
			{
				philo_print(philo, DIED);
				set_done(philo);
				return ;
			}
			++i;
		}
		usleep(OBSERVE_CYCLE);
	}
}