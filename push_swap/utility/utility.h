/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/12 17:00:36 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <stddef.h>
# include "../data_structure/queue.h"

# define CONVERT_NUM 3

int		ft_atoi(const char *str, t_queue *queue);
void	*ft_calloc(size_t nelem, size_t elsize);
char	**ft_split(char const *s, char c);
char	*convert(int data, int size);

#endif