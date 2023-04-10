/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:44:14 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 13:47:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

long	get_time_from(struct timeval *start_time)
{
	struct timeval	cur_time;
	long			sec;
	long			usec;
	
	gettimeofday(&cur_time, NULL);
	sec = (cur_time.tv_sec - start_time->tv_sec) * 1000;
	usec = (cur_time.tv_usec - start_time->tv_usec) / 1000;
	return (sec + usec);
}