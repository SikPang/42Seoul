/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:34:44 by song              #+#    #+#             */
/*   Updated: 2022/12/05 20:47:13 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_last(t_node_ *node, t_list *list, int fd)
{
	char	*result;
	size_t	data_len;

	if (node == 0)
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

int	add_to_data(t_node_ *node, char *buf, ssize_t byte)
{
	char	*temp;

	if (byte == -1)
		return (0);
	temp = node->data;
	node->data = ft_strjoin(node->data, buf, byte);
	if (node->data == 0)
	{
		node->data = temp;
		return (0);
	}
	free(temp);
	return (1);
}

char	*get_result(t_node_ *node, ssize_t new_line_index)
{
	char	*result;
	char	*temp;
	size_t	data_len;

	data_len = 0;
	while (node->data[data_len] != '\0')
		++data_len;
	result = (char *)malloc((new_line_index + 2) * sizeof(char));
	if (result == 0)
		return (0);
	ft_strncpy(result, node->data, new_line_index + 1);
	temp = node->data;
	node->data = (char *)malloc((data_len - new_line_index) * sizeof(char));
	if (node->data == 0)
	{
		free(result);
		node->data = temp;
		return (0);
	}
	ft_strncpy(node->data, temp + new_line_index + 1,
		data_len - new_line_index - 1);
	free(temp);
	return (result);
}

ssize_t	find_new_line(t_node_ *node)
{
	ssize_t	i;

	if (node == 0 || node->data == 0)
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
	t_node_			*target_node;
	char			buf[BUFFER_SIZE];
	ssize_t			byte;
	ssize_t			new_line_index;

	byte = BUFFER_SIZE;
	target_node = find_node(&list, fd, 1);
	while (1)
	{
		new_line_index = find_new_line(target_node);
		if (new_line_index >= 0 || (new_line_index == -1 && byte == 0))
			break ;
		byte = read(fd, buf, BUFFER_SIZE);
		if ((new_line_index == -2 && byte == 0) || byte <= -1)
		{
			delete_node(&list, fd);
			return (0);
		}
		if (target_node == 0 || add_to_data(target_node, buf, byte) == 0)
			return (0);
	}
	if (new_line_index < 0)
		return (get_last(target_node, &list, fd));
	return (get_result(target_node, new_line_index));
}
