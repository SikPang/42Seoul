/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 14:40:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include "utility/utility.h"
#include "philosopher.h"
#include "info.h"

void	wait_all(t_info *info)
{
	int		signal;
	int		i;
	_Bool	is_died;

	i = 0;
	is_died = 0;
	while (i < info->max_philo)
	{
		waitpid(-1, &signal, 0);
		if (WEXITSTATUS(signal) == DEATH_SIGNAL)
		{
			is_died = 1;
			break ;
		}
		++i;
	}
	if (is_died)
	{
		i = 0;
		while (i < info->max_philo)
		{
			kill(info->pids[i], 1);
			++i;
		}
	}
}

void	make_processes(t_info *info)
{
	int		i;

	info->pids = (pid_t *)malloc(info->max_philo * sizeof(pid_t));
	if (info->pids == NULL)
		error_exit(MALLOC);
	while (info->philo.my_number < info->max_philo)
	{
		sem_wait(info->starve[info->philo.my_number]);
		++(info->philo.my_number);
		info->pids[info->philo.my_number - 1] = fork();
		if (info->pids[info->philo.my_number - 1] == 0)
		{
			sem_wait(info->starve[info->philo.my_number - 1]);
			sem_post(info->starve[info->philo.my_number - 1]);
			gettimeofday(&(info->start_time), NULL);
			philo_update(info);
		}
	}
	i = 0;
	while (i < info->max_philo)
	{
		sem_post(info->starve[i]);
		++i;
	}
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 5 && ac != 6)
		error_exit(ARG);
	info = init_info(av);
	make_processes(info);
	wait_all(info);
	unlink_all(info);
	free_all(info);
	return (SUCCESS);
}
