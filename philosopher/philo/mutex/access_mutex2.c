/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_mutex2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:15:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 16:38:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "access_mutex.h"

_Bool	check_done(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->done));
	if (philo->info->cnt_done_eat == philo->info->max_philo)
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

void	increase_done_cnt(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->done));
	++philo->info->cnt_done_eat;
	pthread_mutex_unlock(&(philo->info->done));
}

_Bool	check_starve(t_philo *philo)
{
	long	cur_time;
	int		last_eat;

	pthread_mutex_lock(&(philo->starve));
	last_eat = philo->time_last_eat;
	pthread_mutex_unlock(&(philo->starve));
	cur_time = get_time_from(&(philo->info->start_time));
	if (cur_time - last_eat >= philo->info->time_to_die)
	{
		philo_print(philo, DIED);
		set_dead(philo);
		return (TRUE);
	}
	return (FALSE);
}

void	update_eat_time(t_philo *philo, long cur_time)
{
	pthread_mutex_lock(&(philo->starve));
	philo->time_last_eat = cur_time;
	pthread_mutex_unlock(&(philo->starve));
}
