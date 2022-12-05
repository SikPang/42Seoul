/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:34:44 by song              #+#    #+#             */
/*   Updated: 2022/12/05 15:22:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2, ssize_t byte)
{
	size_t	s1_len;
	char	*new_str;

	if (s1 == 0)
	{
		new_str = (char *)malloc((byte + 1) * sizeof(char));
		ft_memcpy(new_str, s2, byte);
		new_str[byte] = '\0';
		return (new_str);
	}
	s1_len = ft_strlen(s1);
	new_str = (char *)malloc((s1_len + byte + 1) * sizeof(char));
	if (new_str == (char *)0)
		return ((char *)0);
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, byte);
	new_str[s1_len + byte] = '\0';
	return (new_str);
}

t_node	*push_back(t_list *list, int fd, char *data)
{
	t_node	*new_node;
	t_node	*cur_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->prev_node = 0;
	new_node->next_node = 0;
	new_node->fd = fd;
	new_node->data = data;
	new_node->start_index = 0;
	if (list->head == 0)
	{
		new_node->prev_node = 0;
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		cur_node = list->head;
		while (cur_node->next_node != 0)
			cur_node = cur_node->next_node;
		cur_node->next_node = new_node;
		new_node->prev_node = cur_node;
		list->tail = new_node;
	}
	return (new_node);
}

void	erase_node(t_list *list, int fd)
{
	t_node	*node;

	node = find_node(list, fd);
	if (node->prev_node != 0)
		node->prev_node->next_node = node->next_node;
	else
		list->head = node->next_node;
	if (node->next_node != 0)
		node->next_node->prev_node = node->prev_node;
	else
		list->tail = node->prev_node;
	free(node->data);
	free(node);
}

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

char	*get_result(t_node *node, ssize_t new_line_index, ssize_t byte)
{
	char	*result;
	size_t	data_len;

	if (byte == -1)
		return (0);
	data_len = ft_strlen(node->data) - node->start_index;			// here
	result = (char *)malloc(data_len - (new_line_index + 1) + 1);
	if (result == 0)
		return (0);
	ft_memcpy(result, node->data + node->start_index,
		data_len - new_line_index + 1);
	result[data_len - new_line_index + 1] = '\0';
	node->start_index = new_line_index + 1;
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
	char			buf[BUFFER_SIZE];
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
	return (get_result(target_node, new_line_index, byte));
}


/////////////////////


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void print_line(int fd)
{
	char *str = get_next_line(fd);
	printf("return : %s\n-------- \n", str);
	free(str);
}

int main()
{
	int fd = open("t_hello.txt", O_RDONLY);
	printf("fd = %d\n", fd);

	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);

	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);
}