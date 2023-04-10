/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 17:27:01 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include "utility/utility.h"
#include "philosopher.h"
#include "info.h"

void	*observing(void *data)
{
	t_info	*info;
	int		last_eat;

	info = (t_info *)data;
	while (1)
	{
		sem_wait(info->starve[info->philo.my_number - 1]);
		last_eat = info->philo.time_last_eat;
		sem_post(info->starve[info->philo.my_number - 1]);
		if (get_time_from(&(info->start_time)) - last_eat >= info->time_to_die)
		{
			philo_print(info, DIED);
			exit(DEATH_SIGNAL);
		}
		usleep(OBSERVE_CYCLE);
	}
	return (data);
}

void	make_thread(t_info *info)
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
	t_info	*info;

	if (ac != 5 && ac != 6)
		error_exit(ARG);
	info = init_info(av);
	make_thread(info);
	free_all(info);
	return (SUCCESS);
}
