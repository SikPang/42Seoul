/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 20:44:08 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include <stdio.h>

static void	set_starve(t_info *info)
{
	char	*itoa_result;
	char	*file_name;
	int		i;

	info->starve = (sem_t **)malloc(info->max_philo * sizeof(sem_t *));
	if (info->starve == NULL)
		error_exit(MALLOC);
	i = 0;
	while (i < info->max_philo)
	{
		itoa_result = ft_itoa(i);
		file_name = ft_strjoin(FILE_NAME_STARVE, itoa_result);
		info->starve[i] = sem_open(file_name, O_CREAT | O_EXCL, 0666, 1);
		if (info->starve[i] == SEM_FAILED)
			error_exit(SEM);
		free(itoa_result);
		free(file_name);
		++i;
	}
}

static void	set_semaphore(t_info *info)
{
	info->starve = NULL;
	unlink_all(info);
	set_starve(info);
	info->fork = sem_open(FILE_NAME_FORK, O_CREAT | O_EXCL, 0666,
			info->max_philo);
	info->fork_set = sem_open(FILE_NAME_SET, O_CREAT | O_EXCL, 0666,
			info->max_philo / 2);
	info->print = sem_open(FILE_NAME_PRINT, O_CREAT | O_EXCL, 0666, 1);
	if (info->fork == SEM_FAILED || info->fork_set == SEM_FAILED
		|| info->print == SEM_FAILED)
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
	info->must_eat = -1;
	if (av[5] != NULL)
	{
		info->must_eat = ft_atoi(av[5]);
		if (info->must_eat < 1)
			error_exit(ARG);
	}
	set_semaphore(info);
	info->philo.my_number = 0;
	info->philo.count_eat = 0;
	info->philo.state = THINK;
	info->philo.time_last_eat = 0;
	return (info);
}

void	unlink_all(t_info *info)
{
	char	*itoa_result;
	char	*file_name;
	int		i;

	i = 0;
	while (i < info->max_philo)
	{
		itoa_result = ft_itoa(i);
		file_name = ft_strjoin(FILE_NAME_STARVE, itoa_result);
		if (info->starve != NULL)
			sem_close(info->starve[i]);
		sem_unlink(file_name);
		free(itoa_result);
		free(file_name);
		++i;
	}
	sem_close(info->fork);
	sem_unlink(FILE_NAME_FORK);
	sem_close(info->fork_set);
	sem_unlink(FILE_NAME_SET);
	sem_close(info->print);
	sem_unlink(FILE_NAME_PRINT);
}

void	free_all(t_info *info)
{
	unlink_all(info);
	free(info->pids);
	free(info);
}
