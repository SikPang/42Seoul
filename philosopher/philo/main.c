/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 18:23:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include "utility/utility.h"
#include "philosopher.h"
#include "info.h"

void	join_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->max_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		++i;
	}
}

static void	*observing(void *data)
{
	t_philo	*philo;
	long	cur_time;
	int		last_eat;

	info = (t_info *)data;
	cur_time = get_time_from(&(info->start_time));
	while (1)
	{
		sem_wait(info->starve[info->philo.my_number - 1]);
		last_eat = info->philo.time_last_eat;
		sem_post(info->starve[info->philo.my_number - 1]);
		if (cur_time - last_eat >= info->time_to_die)
		{
			philo_print(info, DIED);
			exit(DEATH_SIGNAL);
		}
		usleep(OBSERVE_CYCLE);
	}
	return (data);
}

static void	make_thread(t_philo *philo)
{
	pthread_t	th;
	int	i;

	gettimeofday(&(info->start_time), NULL);
	i = 0;
	while (i < info->max_philo)
	{
		pthread_create(&(info->philo[i].thread), NULL, philo_update,
			(void *)(info->philo));
		++i;
	}
	pthread_create(&th, NULL, observing, (void *)info);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		error_exit(ARG);
	philo = init_philo(av);
	make_thread(philo);
	join_all(philo);
	free_all(philo);
	return (SUCCESS);
}
