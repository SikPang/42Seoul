/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 15:48:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <unistd.h>
#include "philosopher.h"

#include <stdio.h>

static void set_semaphore(t_info *info)
{
	char	*file_name;
	int		i;
	
	info->fork = (sem_t **)malloc(info->max_philo * sizeof(sem_t *));
	if (info->fork == NULL)
		error_exit(MALLOC);
	i = 0;
	while (i < info->max_philo)
	{
		info->fork[i] = (sem_t *)malloc(sizeof(sem_t));
		if (info->fork[i] == NULL)
			error_exit(MALLOC);
		file_name = ft_itoa(i + 214748367);
		info->fork[i] = sem_open(file_name, O_CREAT | O_EXCL, 0666, 0);
    	if (info->fork[i] == SEM_FAILED)
			error_exit(SEM);
		free(file_name);
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
	info->must_eat = 0;
	if (av[5] != NULL)
		info->must_eat = ft_atoi(av[5]);
	set_semaphore(info);
	info->philo.my_number = 0;
	info->philo.count_eat = 0;
	info->philo.state = THINK;
	return (info);
}

void free_info(t_info *info)
{
	char	*file_name;
	int		i;

	i = 0;
	while (i < info->max_philo)
	{
		file_name = ft_itoa(i + 214748367);
		sem_close(info->fork[i]);
		sem_unlink(file_name);
		free(file_name);
		++i;
	}
	free(info->fork);
	free(info);
}