/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:23:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 15:04:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include "info.h"
# include "time/time.h"

# define DEATH_SIGNAL 44
# define OBSERVE_CYCLE 600
# define CHECK_CYCLE 600
# define SUCCESS 0

long	philo_print(t_philo *philo, t_state state);
void	*philo_update(void *philo);
void	observing(t_philo *philo);
_Bool	check_done(t_philo *philo);
void	set_done(t_philo *philo);
void	put_down_fork(t_fork *fork);
_Bool	check_fork(t_fork *fork);

#endif