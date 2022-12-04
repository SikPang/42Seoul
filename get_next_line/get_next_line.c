/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song <song@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:34:44 by song              #+#    #+#             */
/*   Updated: 2022/12/04 22:20:23 by song             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

// 1.	list를 순회하며 fd를 찾음, 해당 fd의 노드가 없으면 push_back
// 2.	해당 노드의 data에서 \n을 찾음
// 3-1.	\n가 있으면 \n까지 substr하여 반환, 종료
// 3-2.	\n이 없으면 read하여 buf 안에 \n이 있는지 탐색
// 4.	list의 data와 buf를 strjoin하여 list의 data에 삽입
// 5.	buf에 \n이 없으면 list의 data에 strjoin하고 3-2로 돌아가서 반복

t_node	*find_node(t_list *list, int fd)
{
	t_node	*node;

	node = list->head;
	while (node != 0)
	{
		if (node->fd == fd)
			break ;
		node = node->next_node;
	}
	return (node);
}

void	add_to_data(t_node *node, char *buf, ssize_t byte)
{
	char	*temp;

	if (byte == -1)
		return ;
	temp = node->data;
	node->data = ft_strjoin(node->data, buf, byte);
	free(temp);
}

char	*get_result(t_node *node, char *buf
	, ssize_t new_line_index, ssize_t byte)
{
	char	*result;
	size_t	data_len;

	if (byte == -1)
		return (0);
	data_len = ft_strlen(node->data) - node->start_index;
	result = (char *)malloc(data_len - node->start_index);
	if (result == 0)
		return (0);
	ft_memcpy(result, node->data + node->start_index,
		data_len - new_line_index);
	result[data_len - new_line_index] = '\0';
	node->start_index = new_line_index;
	return (result);
}

ssize_t	find_new_line(t_node *node)
{
	ssize_t	i;

	if (node->data == 0)
		return (-1);
	i = node->start_index;
	while (node->data[i] != '\0')
	{
		if (node->data[i] == '\n')
			return (i);
		++i;
	}
	if (i == node->start_index)
		return (-2);
	return (-1);
}

char	*get_next_line(int fd)
{
	static t_list	list;
	t_node			*target_node;
	char			*buf;
	ssize_t			byte;
	ssize_t			new_line_index;

	target_node = find_node(&list, fd);
	if (target_node == 0)
		target_node = push_back(&list, fd, 0);
	byte = BUFFER_SIZE;
	while (byte != -1)
	{
		new_line_index = find_new_line(target_node);
		if (new_line_index >= 0)
			break ;
		byte = read(fd, buf, BUFFER_SIZE);
		if (new_line_index == -2 && byte == 0)
		{
			erase_node(&list, fd);
			return (0);
		}
		add_to_data(target_node, buf, byte);
	}
	return (get_result(target_node, buf, new_line_index, byte));
}
