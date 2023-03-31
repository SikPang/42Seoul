/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ks_time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:44:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 20:29:14 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KS_TIME_H
# define KS_TIME_H

# include <unistd.h>
# include <sys/time.h>

int	get_time_from_start(struct timeval *start_time);

#endif