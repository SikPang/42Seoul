/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/07 21:32:23 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <stddef.h>
# include "../data_structure/queue.h"

int		ft_atoi(const char *str, t_queue *queue);
void	*ft_calloc(size_t nelem, size_t elsize);
char	**ft_split(char const *s, char c);

#endif