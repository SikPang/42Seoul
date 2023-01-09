/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:17:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/09 20:08:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*get_last(char **str, ssize_t byte)
{
	char	*result;
	size_t	data_len;

	data_len = 0;
	while (*str && (*str)[data_len])
		++data_len;
	if (byte < 0 || data_len == 0)
	{
		free(*str);
		*str = 0;
		return (0);
	}
	result = (char *)malloc(data_len + 1);
	ft_strncpy(result, *str, data_len);
	free(*str);
	*str = 0;
	return (result);
}

char	*get_result(char **str, size_t result_len, size_t data_len)
{
	char	*result;
	char	*temp;

	while (*str && (*str)[data_len])
		++data_len;
	result = (char *)malloc(result_len + 1);
	ft_strncpy(result, *str, result_len);
	temp = *str;
	*str = (char *)malloc(data_len - result_len + 1);
	ft_strncpy(*str, temp + result_len, data_len - result_len);
	free(temp);
	return (result);
}

ssize_t	read_buf(char **str, int fd)
{
	char	*buf;
	char	*temp;
	ssize_t	byte;

	buf = (char *)malloc(BUFFER_SIZE);
	while (1)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		temp = *str;
		*str = ft_strjoin(*str, buf, byte);
		free(temp);
		if (ft_strchr(*str, '\n') != 0)
			break ;
	}
	free(buf);
	return (byte);
}

char	*get_next_line(int fd)
{
	static char		*str;
	size_t			result_len;
	ssize_t			byte;

	if (BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		result_len = ft_strchr(str, '\n');
		if (result_len > 0)
			return (get_result(&str, result_len, 0));
		byte = read_buf(&str, fd);
		if (byte <= 0)
			return (get_last(&str, byte));
	}
}
