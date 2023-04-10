/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 21:14:21 by kwsong           ###   ########.fr       */
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
	while (i < philo->info->max_philo)
	{
		pthread_join(philo[i].thread, NULL);
		++i;
	}
}

static void	observing(t_philo *philo)
{
	long	cur_time;
	int		last_eat;
	int		i;

	while (1)
	{
		cur_time = get_time_from(&(philo[0].info->start_time));
		i = 0;
		while (i < philo[0].info->max_philo)
		{
			if (philo[0].info->is_over == TRUE)
				return ;
			pthread_mutex_lock(&(philo->starve));
			last_eat = philo->time_last_eat;
			pthread_mutex_unlock(&(philo->starve));
			if (cur_time - last_eat >= philo[0].info->time_to_die)
			{
				philo_print(philo, DIED);
				philo[0].info->is_over = TRUE;
				return ;
			}
			++i;
		}
		usleep(OBSERVE_CYCLE);
	}
}

static void	make_thread(t_philo *philo)
{
	pthread_t	obs_thread;
	int			i;

	gettimeofday(&(philo->info->start_time), NULL);
	i = 0;
	while (i < philo->info->max_philo)
	{
		pthread_create(&(philo[i].thread), NULL, philo_update,
			(void *)(philo + i));
		++i;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		error_exit(ARG);
	philo = init_philo(av);
	make_thread(philo);
	observing(philo);
	join_all(philo);
	free_all(philo);
	return (SUCCESS);
}
