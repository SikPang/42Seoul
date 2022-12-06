/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:34:44 by song              #+#    #+#             */
/*   Updated: 2022/12/06 16:27:13 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

// char	*ft_strncpy(char *dest, const char *src, size_t n)
// {
// 	size_t	i;

// 	if (!dest && !src)
// 		return (dest);
// 	i = 0;
// 	while (i < n)
// 	{
// 		dest[i] = src[i];
// 		++i;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_strjoin(char const *s1, char const *s2, ssize_t byte)
// {
// 	size_t	s1_len;
// 	char	*new_str;

// 	if (s1 == 0)
// 	{
// 		new_str = (char *)malloc((byte + 1) * sizeof(char));
// 		if (new_str == 0)
// 			return (0);
// 		ft_strncpy(new_str, s2, byte);
// 		return (new_str);
// 	}
// 	s1_len = 0;
// 	while (s1[s1_len] != '\0')
// 		++s1_len;
// 	new_str = (char *)malloc((s1_len + byte + 1) * sizeof(char));
// 	if (new_str == 0)
// 		return (0);
// 	ft_strncpy(new_str, s1, s1_len);
// 	ft_strncpy(new_str + s1_len, s2, byte);
// 	return (new_str);
// }

// t_node_	*find_node(t_list *list, int fd, int check)
// {
// 	t_node_	*node;

// 	node = list->head;
// 	while (node != 0)
// 	{
// 		if (node->fd == fd)
// 			return (node);
// 		node = node->next_node;
// 	}
// 	if (check == 1)
// 		return (push_back(list, fd));
// 	else
// 		return (0);
// }

// t_node_	*push_back(t_list *list, int fd)
// {
// 	t_node_	*new_node;
// 	t_node_	*cur_node;

// 	new_node = (t_node_ *)malloc(sizeof(t_node_));
// 	if (new_node == 0)
// 		return (0);
// 	new_node->prev_node = 0;
// 	new_node->next_node = 0;
// 	new_node->fd = fd;
// 	new_node->data = 0;
// 	if (list->head == 0)
// 	{
// 		list->head = new_node;
// 		list->tail = new_node;
// 	}
// 	else
// 	{
// 		cur_node = list->head;
// 		while (cur_node->next_node != 0)
// 			cur_node = cur_node->next_node;
// 		cur_node->next_node = new_node;
// 		new_node->prev_node = cur_node;
// 		list->tail = new_node;
// 	}
// 	return (new_node);
// }

// void	delete_node(t_list *list, int fd)
// {
// 	t_node_	*node;

// 	node = find_node(list, fd, 0);
// 	if (node == 0)
// 		return ;
// 	if (node->prev_node != 0)
// 		node->prev_node->next_node = node->next_node;
// 	else
// 		list->head = node->next_node;
// 	if (node->next_node != 0)
// 		node->next_node->prev_node = node->prev_node;
// 	else
// 		list->tail = node->prev_node;
// 	free(node->data);
// 	free(node);
// 	free(list->buf);
// }

char	*get_last(t_node_ *node, t_list *list, int fd, ssize_t nl_index)
{
	char	*result;
	size_t	data_len;

	if (node == 0 || nl_index == -3)
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

char	*get_result(t_node_ *node, ssize_t nl_index)
{
	char	*result;
	char	*temp;
	size_t	data_len;

	if (node == 0 || nl_index == -3)
		return (0);
	data_len = 0;
	while (node->data[data_len] != '\0')
		++data_len;
	result = (char *)malloc((nl_index + 2) * sizeof(char));
	if (result == 0)
		return (0);
	ft_strncpy(result, node->data, nl_index + 1);
	temp = node->data;
	node->data = (char *)malloc((data_len - nl_index) * sizeof(char));
	if (node->data == 0)
	{
		free(result);
		node->data = temp;
		return (0);
	}
	ft_strncpy(node->data, temp + nl_index + 1,
		data_len - nl_index - 1);
	free(temp);
	return (result);
}

ssize_t	find_new_line(t_node_ *node, t_list *list)
{
	ssize_t	i;

	free(list->buf);
	list->buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (list->buf == 0)
		return (-3);
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
	return (get_result(target, nl_index));
}

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// void print_line(int fd)
// {
// 	char *str = get_next_line(fd);
// 	printf("return : %s\n-------- \n", str);
// 	free(str);
// }

// int main()
// {
// 	int fd = open("t_hello.txt", O_RDONLY);
// 	printf("fd = %d\n", fd);

// 	print_line(fd);
// 	print_line(fd);
// 	print_line(fd);
// 	print_line(fd);
// 	print_line(fd);

// 	print_line(fd);
// 	print_line(fd);
// 	print_line(fd);
// 	print_line(fd);
// 	print_line(fd);
// }