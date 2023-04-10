/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 21:14:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "info.h"

static void	set_fork(t_info *info)
{
	int	i;

	info->fork = (t_fork *)malloc(info->max_philo * sizeof(t_fork));
	if (info->fork == NULL)
		error_exit(MALLOC);
	i = 0;
	while (i < info->max_philo)
	{
		pthread_mutex_init(&(info->fork[i].mutex), NULL);
		info->fork[i].state = AVAILAVLE;
		++i;
	}
}

t_philo	*set_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(info->max_philo * sizeof(t_philo));
	if (philo == NULL)
		error_exit(MALLOC);
	i = 0;
	while (i < info->max_philo)
	{
		pthread_mutex_init(&(philo[i].starve), NULL);
		philo[i].time_last_eat = 0;
		philo[i].my_number = i + 1;
		philo[i].count_eat = 0;
		philo[i].state = THINK;
		philo[i].info = info;
		philo[i].left_idx = philo[i].my_number - 1 - ((i + 1) % 2);
		philo[i].right_idx = philo[i].my_number - 2 + ((i + 1) % 2);
		++i;
	}
	philo[0].left_idx = info->max_philo - 1;
	return (philo);
}

t_philo	*init_philo(char **av)
{
	t_info	*info;
	t_philo	*philo;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		error_exit(MALLOC);
	info->max_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (info->max_philo < 1 || info->max_philo > 1000 || info->time_to_die < 1
		|| info->time_to_eat < 1 || info->time_to_sleep < 1)
		error_exit(ARG);
	info->must_eat = -1;
	if (av[5] != NULL)
	{
		info->must_eat = ft_atoi(av[5]);
		if (info->must_eat < 1)
			error_exit(ARG);
	}
	info->is_over = FALSE;
	set_fork(info);
	pthread_mutex_init(&(info->print), NULL);
	philo = set_philo(info);
	return (philo);
}

void	free_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->max_philo)
	{
		pthread_mutex_destroy(&(philo->info->fork[i].mutex));
		pthread_mutex_destroy(&(philo[i].starve));
		++i;
	}
	pthread_mutex_destroy(&(philo->info->print));
	free(philo->info->fork);
	free(philo->info);
	free(philo);
}
