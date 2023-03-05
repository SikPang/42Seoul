/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/31 22:14:07 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_BONUS_H
# define UTILITY_BONUS_H

# include <stddef.h>
# include "../data_structure/list_bonus.h"

char	*ft_itoa(int n);
int		ft_atoh(char *str);
int		ft_atoi(char *str, int *color);
void	*ft_calloc(size_t nelem, size_t elsize);
char	**ft_split(char const *s, char c);
void	error_exit(void);

#endif