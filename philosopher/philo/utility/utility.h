/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/10 20:31:17 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <stddef.h>

# define ERROR 1

typedef enum e_error
{
	ARG,
	MALLOC,
	MUTEX,
	THREAD
}	t_error;

int		ft_atoi(const char *str);
void	error_exit(t_error code);

#endif