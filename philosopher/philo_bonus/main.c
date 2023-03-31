/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 20:42:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utility/utility.h"
#include "philosopher.h"
#include "info.h"

void	wait_all(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->max_philo)
	{
		wait(NULL);
		++i;
	}
}

void make_processes(t_info *info)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < info->max_philo)
	{
		pid = fork();
		if (pid == 0)
			philo_update(info);
		++(info->philo.my_number);
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
	free_info(info);
}