/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:23:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 15:39:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <semaphore.h>
# include <stdlib.h>
# include "utility/utility.h"

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK
} t_state;

typedef struct s_philo
{
	int my_number;
	int count_eat;
	t_state state;
} t_philo;

typedef struct s_info
{
	t_philo philo;
	sem_t **fork;
	int max_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int must_eat;
} t_info;

t_info	*init_info(char **av);
void free_info(t_info *info);

#endif