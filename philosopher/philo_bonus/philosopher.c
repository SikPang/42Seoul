/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 20:57:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosopher.h"
#include "info.h"
#include "time/ks_time.h"

static void philo_print(t_info *info, t_state state)
{
	int	time;

	sem_wait(info->print);
	time = get_time_from_start(&(info->start_time));
	if (state == THINK)
		printf("%d %d is thinking\n", time, info->philo.my_number);
	else if (state == SLEEP)
		printf("%d %d is sleeping\n", time, info->philo.my_number);
	else if (state == EAT)
	{
		printf("%d %d has taken a fork\n", time, info->philo.my_number);
		printf("%d %d has taken a fork\n", time, info->philo.my_number);
		printf("%d %d is eating\n", time, info->philo.my_number);
	}
	sem_post(info->print);
}

static void	philo_eat(t_info *info)
{
	philo_print(info, EAT);
	usleep(info->time_to_eat * 1000);
	sem_post(info->fork);
	sem_post(info->fork);
	sem_post(info->fork_set);
	info->philo.state = SLEEP;
}

static void	philo_sleep(t_info *info)
{
	philo_print(info, SLEEP);
	usleep(info->time_to_sleep * 1000);
	info->philo.state = THINK;
}

static void	philo_think(t_info *info)
{
	philo_print(info, THINK);
	sem_wait(info->fork_set);
	sem_wait(info->fork);
	sem_wait(info->fork);
	info->philo.state = EAT;
}

void	philo_update(t_info *info)
{
	while (1)
	{
		if (info->philo.state == THINK)
			philo_think(info);
		else if (info->philo.state == EAT)
			philo_eat(info);
		else if (info->philo.state == SLEEP)
			philo_sleep(info);
	}
}