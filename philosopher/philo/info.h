/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:23:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 17:08:07 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include "utility/utility.h"

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK,
	DIED,
	AVAILAVLE,
	UNAVAILAVLE
}	t_state;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	starve;
	int				time_last_eat;
	int				my_number;
	int				count_eat;
	t_state			state;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t mutex;
	t_state			state;
}	t_fork;

typedef struct s_info
{
	t_philo			*philo;
	t_fork			*fork;
	pthread_mutex_t	print;
	struct timeval	start_time;
	int				max_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}	t_info;

t_info	*init_info(char **av);
void	free_all(t_info *info);

#endif