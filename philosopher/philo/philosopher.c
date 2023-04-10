/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 17:27:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	philo_print(t_philo *philo, t_state state)
{
	long	time;

	sem_wait(info->print);
	time = get_time_from(&(info->start_time));
	if (state == THINK)
		printf("%ld %d is thinking\n", time, info->philo.my_number);
	else if (state == SLEEP)
		printf("%ld %d is sleeping\n", time, info->philo.my_number);
	else if (state == EAT)
	{
		printf("%ld %d has taken a fork\n", time, info->philo.my_number);
		printf("%ld %d has taken a fork\n", time, info->philo.my_number);
		printf("%ld %d is eating\n", time, info->philo.my_number);
	}
	else if (state == DIED)
	{
		printf("%ld %d is died\n", time, info->philo.my_number);
		return (time);
	}
	sem_post(info->print);
	return (time);
}

static void	philo_eat(t_philo *philo)
{
	long	cur_time;

	cur_time = philo_print(info, EAT);
	sem_wait(info->starve[info->philo.my_number - 1]);
	info->philo.time_last_eat = cur_time;
	sem_post(info->starve[info->philo.my_number - 1]);
	while (get_time_from(&(info->start_time)) - cur_time < info->time_to_eat)
		usleep(CHECK_CYCLE);
	++(info->philo.count_eat);
	sem_post(info->fork);
	sem_post(info->fork);
	sem_post(info->fork_set);
	if (info->philo.count_eat == info->must_eat)
		exit(SUCCESS);
	info->philo.state = SLEEP;
}

static void	philo_sleep(t_philo *philo)
{	
	long	cur_time;

	cur_time = philo_print(info, SLEEP);
	while (get_time_from(&(info->start_time)) - cur_time < info->time_to_sleep)
		usleep(CHECK_CYCLE);
	info->philo.state = THINK;
}

static void	philo_think(t_philo *philo)
{
	philo_print(info, THINK);
	sem_wait(info->fork_set);
	sem_wait(info->fork);
	sem_wait(info->fork);
	info->philo.state = EAT;
}

void	philo_update(t_philo *philo)
{
	while (1)
	{
		if (philo->state == THINK)
			philo_think(philo);
		else if (philo->state == EAT)
			philo_eat(philo);
		else if (philo->state == SLEEP)
			philo_sleep(philo);
	}
}
