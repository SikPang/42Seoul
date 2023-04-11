/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_mutex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:16:04 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/11 16:20:13 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS_MUTEX_H
# define ACCESS_MUTEX_H

# include "../philosopher.h"

_Bool	check_dead(t_philo *philo);
void	set_dead(t_philo *philo);
_Bool	check_fork(t_fork *fork);
void	put_down_fork(t_fork *fork);
_Bool	check_starve(t_philo *philo);
void	update_eat_time(t_philo *philo, long cur_time);
_Bool	check_done(t_philo *philo);
void	increase_done_cnt(t_philo *philo);

#endif