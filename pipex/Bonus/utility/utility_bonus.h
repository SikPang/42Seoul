/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:04:12 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/04 16:18:55 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_BONUS_H
# define UTILITY_BONUS_H

# include <stddef.h>

size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
char	**ft_split(char const *s, char c);
void	error_exit(void);

#endif