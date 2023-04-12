/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/12 11:50:21 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mutex/access_mutex.h"
#include "philosopher.h"

long	philo_print(t_philo *philo, t_state state)
{
	long	time;

	pthread_mutex_lock(&(philo->info->print));
	time = get_time_from(&(philo->info->start_time));
	if (state != DIED && check_dead(philo) == TRUE)
	{
		pthread_mutex_unlock(&(philo->info->print));
		return (0);
	}
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
		pthread_mutex_unlock(&(philo->info->print));
		return (time);
	}
	pthread_mutex_unlock(&(philo->info->print));
	return (time);
}

static void	philo_eat(t_philo *philo)
{
	long	cur_time;

	cur_time = philo_print(philo, EAT);
	update_eat_time(philo, cur_time);
	if (philo_usleep(philo, cur_time, philo->info->time_to_eat) == FALSE)
		return ;
	++(philo->count_eat);
	put_down_fork(philo->info->fork + philo->left_idx);
	put_down_fork(philo->info->fork + philo->right_idx);
	philo->state = SLEEP;
}

static void	philo_sleep(t_philo *philo)
{	
	long	cur_time;

	cur_time = philo_print(philo, SLEEP);
	if (philo_usleep(philo, cur_time, philo->info->time_to_sleep) == FALSE)
		return ;
	philo->state = THINK;
}

static void	philo_think(t_philo *philo, _Bool is_first)
{
	long	cur_time;

	cur_time = philo_print(philo, THINK);
	if (!is_first
		&& philo_usleep(philo, cur_time, philo->info->time_to_think) == FALSE)
		return ;
	while (check_fork(philo->info->fork + philo->left_idx) == FALSE)
		if (check_dead(philo) == TRUE)
			return ;
	philo_print(philo, FORK);
	while (check_fork(philo->info->fork + philo->right_idx) == FALSE)
	{
		if (check_dead(philo) == TRUE)
		{
			put_down_fork(philo->info->fork + philo->left_idx);
			return ;
		}
	}
	philo_print(philo, FORK);
	if (check_dead(philo) == TRUE)
	{
		put_down_fork(philo->info->fork + philo->left_idx);
		put_down_fork(philo->info->fork + philo->right_idx);
	}
	philo->state = EAT;
}

void	*philo_update(void *data)
{
	t_philo	*philo;
	_Bool	is_first;

	philo = (t_philo *)data;
	is_first = TRUE;
	if (philo->my_number % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (philo->state == THINK)
			philo_think(philo, is_first);
		else if (philo->state == EAT)
			philo_eat(philo);
		else if (philo->state == SLEEP)
			philo_sleep(philo);
		if (check_dead(philo) == TRUE)
			return (NULL);
		if (philo->count_eat == philo->info->must_eat)
		{
			increase_done_cnt(philo);
			return (NULL);
		}
		is_first = FALSE;
	}
}
