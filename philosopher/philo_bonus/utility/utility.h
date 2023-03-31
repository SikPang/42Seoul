/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/31 15:17:34 by kwsong           ###   ########.fr       */
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
char	*ft_itoa(int n);
void	error_exit(t_error code);

#endif