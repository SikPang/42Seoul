/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:23:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 18:58:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include "utility/utility.h"

# define TRUE 1
# define FALSE 0

typedef enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED,
}	t_state;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	_Bool			is_available;
}	t_fork;

typedef struct s_info
{
	t_fork			*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	died;
	pthread_mutex_t	done;
	struct timeval	start_time;
	int				max_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				must_eat;
	int				cnt_done_eat;
	_Bool			is_died;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	starve;
	int				time_last_eat;
	int				my_number;
	int				count_eat;
	int				left_idx;
	int				right_idx;
	t_state			state;
	t_info			*info;
}	t_philo;

t_philo	*init_philo(char **av);
void	free_all(t_philo *philo);

#endif