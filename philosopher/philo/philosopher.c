/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 21:01:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	philo_print(t_philo *philo, t_state state)
{
	long	time;

	pthread_mutex_lock(&(philo->info->print));
	if (philo[0].info->is_over == TRUE)
	{
		pthread_mutex_unlock(&(philo->info->print));
		return (time);
	}
	time = get_time_from(&(philo->info->start_time));
	if (state == THINK)
		printf("%ld %d is thinking\n", time, philo->my_number);
	else if (state == SLEEP)
		printf("%ld %d is sleeping\n", time, philo->my_number);
	else if (state == FORK)
		printf("%ld %d has taken a fork\n", time, philo->my_number);
	else if (state == EAT)
		printf("%ld %d is eating\n", time, philo->my_number);
	else if (state == DIED)
	{
		printf("%ld %d is died\n", time, philo->my_number);
		return (time);
	}
	pthread_mutex_unlock(&(philo->info->print));
	return (time);
}

static void	philo_eat(t_philo *philo)
{
	long	cur_time;

	cur_time = philo_print(philo, EAT);
	pthread_mutex_lock(&(philo->starve));
	philo->time_last_eat = cur_time;
	pthread_mutex_unlock(&(philo->starve));
	while (get_time_from(&(philo->info->start_time)) - cur_time
		< philo->info->time_to_eat)
	{
		if (philo[0].info->is_over == TRUE)
		{
			pthread_mutex_unlock(&(philo->info->fork[philo->left_idx].mutex));
			pthread_mutex_unlock(&(philo->info->fork[philo->right_idx].mutex));
			return ;
		}
		usleep(CHECK_CYCLE);
	}
	++(philo->count_eat);
	pthread_mutex_unlock(&(philo->info->fork[philo->left_idx].mutex));
	philo->info->fork[philo->left_idx].state = AVAILAVLE;
	pthread_mutex_unlock(&(philo->info->fork[philo->right_idx].mutex));
	philo->info->fork[philo->right_idx].state = AVAILAVLE;
	if (philo->count_eat == philo->info->must_eat)
		philo[0].info->is_over = TRUE;
	philo->state = SLEEP;
}

static void	philo_sleep(t_philo *philo)
{	
	long	cur_time;

	cur_time = philo_print(philo, SLEEP);
	while (get_time_from(&(philo->info->start_time)) - cur_time
		< philo->info->time_to_sleep)
	{
		if (philo[0].info->is_over == TRUE)
			return ;
		usleep(CHECK_CYCLE);
	}
	philo->state = THINK;
}

static void	philo_think(t_philo *philo)
{
	philo_print(philo, THINK);
	while (philo->info->fork[philo->left_idx].state == UNAVAILAVLE)
		if (philo[0].info->is_over == TRUE)
			return ;
	philo->info->fork[philo->left_idx].state = UNAVAILAVLE;
	pthread_mutex_lock(&(philo->info->fork[philo->left_idx].mutex));
	philo_print(philo, FORK);
	while (philo->info->fork[philo->right_idx].state == UNAVAILAVLE)
	{
		if (philo[0].info->is_over == TRUE)
		{
			pthread_mutex_unlock(&(philo->info->fork[philo->left_idx].mutex));
			return ;
		}
	}
	philo->info->fork[philo->right_idx].state = UNAVAILAVLE;
	pthread_mutex_lock(&(philo->info->fork[philo->right_idx].mutex));
	philo_print(philo, FORK);
	if (philo[0].info->is_over == TRUE)
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->left_idx].mutex));
		pthread_mutex_unlock(&(philo->info->fork[philo->right_idx].mutex));
	}
	philo->state = EAT;
}

void	*philo_update(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (philo[0].info->is_over == TRUE)
			return (NULL);
		if (philo->state == THINK)
			philo_think(philo);
		else if (philo->state == EAT)
			philo_eat(philo);
		else if (philo->state == SLEEP)
			philo_sleep(philo);
	}
}
