/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:23:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/12 12:19:23 by kwsong           ###   ########.fr       */
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
# define START_DELAY 1000
# define SUCCESS 0

long	philo_print(t_info *info, t_state state);
void	philo_update(t_info *info);
void	*observing(void *data);

#endif