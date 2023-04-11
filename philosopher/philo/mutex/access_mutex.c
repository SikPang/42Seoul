/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:28:26 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 16:37:44 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "access_mutex.h"

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

_Bool	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->died));
	if (philo->info->is_died == TRUE)
	{
		pthread_mutex_unlock(&(philo->info->died));
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(&(philo->info->died));
		return (FALSE);
	}
}

void	set_dead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->died));
	philo->info->is_died = TRUE;
	pthread_mutex_unlock(&(philo->info->died));
}
