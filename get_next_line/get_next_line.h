/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:52:07 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/01 22:18:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <stddef.h>

void	ft_strncpy(char *dest, char *src, size_t start_index, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*get_next_line(int fd);

#endif