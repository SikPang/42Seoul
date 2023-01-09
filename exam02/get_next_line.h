/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:18:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/09 20:06:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, ssize_t byte);
char	*get_last(char **str, ssize_t byte);
char	*get_result(char **str, size_t result_len, size_t data_len);
size_t	ft_strchr(char *s, char c);
ssize_t	read_buf(char **str, int fd);
char	*get_next_line(int fd);

#endif
