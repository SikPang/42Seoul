/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/04 20:57:19 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void set_semaphore(t_info *info)
{
	info->fork = sem_open(FILE_NAME_FORK, O_CREAT | O_EXCL, 0666,
		info->max_philo);
	info->fork_set = sem_open(FILE_NAME_SET, O_CREAT | O_EXCL, 0666,
		info->max_philo / 2);
	info->print = sem_open(FILE_NAME_PRINT, O_CREAT | O_EXCL, 0666, 1);
	info->starve = sem_open(FILE_NAME_STARVE, O_CREAT | O_EXCL, 0666, 1);
    if (info->fork == SEM_FAILED || info->fork_set == SEM_FAILED
		|| info->print == SEM_FAILED || info->starve == SEM_FAILED)
		error_exit(SEM);
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
	unlink_all(info);
	set_semaphore(info);
	gettimeofday(&(info->start_time), NULL);
	info->philo.my_number = 0;
	info->philo.count_eat = 0;
	info->philo.state = THINK;
	info->philo.time_last_eat = 0;
	return (info);
}

void unlink_all(t_info *info)
{
	sem_close(info->fork);
	sem_unlink(FILE_NAME_FORK);
	sem_close(info->fork_set);
	sem_unlink(FILE_NAME_SET);
	sem_close(info->print);
	sem_unlink(FILE_NAME_PRINT);
	sem_close(info->starve);
	sem_unlink(FILE_NAME_STARVE);
}

void free_all(t_info *info)
{
	unlink_all(info);
	free(info->pids);
	free(info);
}
