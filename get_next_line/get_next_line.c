/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:34:44 by song              #+#    #+#             */
/*   Updated: 2022/12/06 21:06:51 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_last(t_node_ *node, t_list *list, int fd, ssize_t nl_index)
{
	char	*result;
	size_t	data_len;

	if (node == 0 || node->data == 0 || nl_index == -3)
		return (0);
	data_len = 0;
	while (node->data[data_len] != '\0')
		++data_len;
	result = (char *)malloc((data_len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	ft_strncpy(result, node->data, data_len);
	delete_node(list, fd);
	return (result);
}

char	*get_result(t_node_ *node, ssize_t result_len, size_t data_len)
{
	char	*result;
	char	*temp;

	if (node == 0 || node->data == 0 || result_len == -2)
		return (0);
	while (node->data[data_len] != '\0')
		++data_len;
	if (result_len <= 0)
		result_len = data_len;
	result = (char *)malloc((result_len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	ft_strncpy(result, node->data, result_len);
	temp = node->data;
	node->data = (char *)malloc((data_len - result_len + 1) * sizeof(char));
	if (node->data == 0)
	{
		free(result);
		node->data = temp;
		return (0);
	}
	ft_strncpy(node->data, temp + result_len, data_len - result_len);
	free(temp);
	return (result);
}

int	add_to_data(t_list *list, t_node_ *node, ssize_t byte)
{
	char	*temp;

	if (byte == -1)
	{
		free(list->buf);
		return (0);
	}
	temp = node->data;
	node->data = ft_strjoin(node->data, list->buf, byte);
	if (node->data == 0)
	{
		node->data = temp;
		free(list->buf);
		return (0);
	}
	free(temp);
	return (1);
}

ssize_t	find_new_line(t_node_ *node, t_list *list)
{
	ssize_t	i;

	if (node == 0)
		return (-3);
	free(list->buf);
	list->buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (list->buf == 0)
		return (-3);
	if (node->data == 0)
		return (-1);
	i = 0;
	while (node->data[i] != '\0')
	{
		if (node->data[i] == '\n')
			return (i);
		++i;
	}
	if (i == 0)
		return (-2);
	return (-1);
}

char	*get_next_line(int fd)
{
	static t_list	list;
	t_node_			*target;
	ssize_t			byte;
	ssize_t			nl_index;

	byte = BUFFER_SIZE;
	target = find_node(&list, fd, 1);
	while (1)
	{
		nl_index = find_new_line(target, &list);
		if (nl_index >= 0 || (nl_index == -1 && byte == 0) || nl_index == -3)
			break ;
		byte = read(fd, list.buf, BUFFER_SIZE);
		if ((nl_index == -2 && byte == 0) || byte <= -1)
		{
			delete_node(&list, fd);
			return (0);
		}
		if (target == 0 || add_to_data(&list, target, byte) == 0)
			break ;
	}
	if (nl_index < 0)
		return (get_last(target, &list, fd, nl_index));
	return (get_result(target, nl_index + 1, 0));
}
