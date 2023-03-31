/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 20:24:19 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

typedef enum e_error
{
	ARG,
	MALLOC,
	FORK,
	SEM
} t_error;

int		ft_atoi(const char *str);
void	error_exit(t_error code);

#endif