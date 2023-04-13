/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/12 12:37:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include "utility/utility.h"
#include "philosopher.h"
#include "mutex/access_mutex.h"
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
	if (check_done(philo) == TRUE)
		printf("%ld done !\n", get_time_from(&(philo->info->start_time)));
}

static void	make_thread(t_philo *philo)
{
	int	i;

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
