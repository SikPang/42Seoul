/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ks_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:44:14 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 20:46:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ks_time.h"

int	get_time_from_start(struct timeval *start_time)
{
	struct timeval	cur_time;
	int				sec;
	int				usec;
	
	gettimeofday(&cur_time, NULL);
	sec = (cur_time.tv_sec - start_time->tv_sec) * 1000;
	usec = (cur_time.tv_usec - start_time->tv_usec) / 1000;
	return (sec + usec);
}