/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:23:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/12 12:19:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include "info.h"
# include "time/time.h"

# define OBSERVE_CYCLE 600
# define CHECK_CYCLE 600
# define START_DELAY 1000
# define SUCCESS 0

long	philo_print(t_philo *philo, t_state state);
void	*philo_update(void *philo);
void	observing(t_philo *philo);
_Bool	philo_usleep(t_philo *philo, long start_time, int time_for_wait);

#endif