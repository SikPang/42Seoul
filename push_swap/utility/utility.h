/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/13 21:02:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <stddef.h>

# define CONVERT_NUM 3

int		ft_atoi(const char *str);
void	*ft_calloc(size_t nelem, size_t elsize);
char	**ft_split(char const *s, char c);
char	*convert(int data, int size);
void	error_exit(void);

#endif