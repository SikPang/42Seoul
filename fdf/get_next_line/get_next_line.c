/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:17:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/29 15:47:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "../utility/utility.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_last(t_glist *list, t_gnode *target, ssize_t byte)
{
	char	*result;
	size_t	data_len;

	data_len = 0;
	while (target->data && target->data[data_len])
		++data_len;
	if (byte < 0 || data_len == 0)
	{
		delete_node(list, target);
		return (0);
	}
	result = (char *)malloc(data_len + 1);
	if (result == 0)
	{
		delete_node(list, target);
		return (0);
	}
	ft_strncpy(result, target->data, data_len);
	delete_node(list, target);
	return (result);
}

char	*get_result(t_glist *list, t_gnode *target, size_t result_len,
	size_t data_len)
{
	char	*result;
	char	*temp;

	while (target->data && target->data[data_len])
		++data_len;
	result = (char *)malloc(result_len + 1);
	if (result == 0)
	{
		delete_node(list, target);
		return (0);
	}
	ft_strncpy(result, target->data, result_len);
	temp = target->data;
	target->data = (char *)malloc(data_len - result_len + 1);
	if (target->data == 0)
	{
		free(result);
		target->data = temp;
		delete_node(list, target);
		return (0);
	}
	ft_strncpy(target->data, temp + result_len, data_len - result_len);
	free(temp);
	return (result);
}

ssize_t	read_buf(t_gnode *target, int fd)
{
	char	*buf;
	char	*temp;
	ssize_t	byte;

	buf = (char *)malloc(BUFFER_SIZE);
	if (buf == 0)
		return (-2);
	while (1)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		temp = target->data;
		target->data = ft_strjoin(target->data, buf, byte);
		if (target->data == 0)
		{
			target->data = temp;
			return (-2);
		}
		free(temp);
		if (ft_strchr(target->data, '\n') != 0)
			break ;
	}
	free(buf);
	return (byte);
}

char	*get_next_line(int fd)
{
	static t_glist	list;
	t_gnode			*target;
	size_t			result_len;
	ssize_t			byte;

	if (BUFFER_SIZE <= 0)
		return (0);
	target = find_node(&list, fd);
	if (target == 0)
		return (0);
	while (1)
	{
		result_len = ft_strchr(target->data, '\n');
		if (result_len > 0)
			return (get_result(&list, target, result_len, 0));
		byte = read_buf(target, fd);
		if (byte == 0)
			return (get_last(&list, target, byte));
		else if (byte == -1)
			error_exit();
	}
}
