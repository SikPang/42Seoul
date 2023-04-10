/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 17:10:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	set_philo(t_info *info)
{
	int	i;

	info->philo = (t_philo *)malloc(info->max_philo * sizeof(t_philo));
	if (info->philo == NULL)
		error_exit(MALLOC);
	i = 0;
	while (i < info->max_philo)
	{
		pthread_mutex_init(&(info->philo[i].starve), NULL);
		info->philo[i].time_last_eat = 0;
		info->philo[i].my_number = 0;
		info->philo[i].count_eat = 0;
		info->philo[i].state = THINK;
		++i;
	}
}

t_info	*init_info(char **av)
{
	t_info	*info;

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
	set_philo(info);
	set_fork(info);
	pthread_mutex_init(&(info->print), NULL);
	return (info);
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->max_philo)
	{
		pthread_mutex_destroy(&(info->fork[i].mutex));
		pthread_mutex_destroy(&(info->philo[i].starve));
		++i;
	}
	pthread_mutex_destroy(&(info->print));
	free(info->philo);
	free(info->fork);
	free(info);
}