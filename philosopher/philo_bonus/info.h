/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:23:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 20:23:56 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include "utility/utility.h"

# define FILE_NAME_FORK "/fork_semaphore"
# define FILE_NAME_SET "/set_semaphore"
# define FILE_NAME_PRINT "/print_semaphore"

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK
} t_state;

typedef struct s_philo
{
	struct timeval	starving_time;
	int 			my_number;
	int 			count_eat;
	t_state 		state;
} t_philo;

typedef struct s_info
{
	struct timeval	start_time;
	t_philo 		philo;
	sem_t 			*fork;
	sem_t 			*fork_set;
	sem_t 			*print;
	int 			max_philo;
	int 			time_to_die;
	int 			time_to_eat;
	int				time_to_sleep;
	int 			must_eat;
} t_info;

t_info	*init_info(char **av);
void free_info(t_info *info);

#endif