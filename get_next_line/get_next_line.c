/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:17:53 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/09 15:45:48 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

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

char	*get_last(t_list *list, t_node_ *target, ssize_t byte)
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

char	*get_result(t_list *list, t_node_ *target, size_t result_len,
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

ssize_t	read_buf(t_node_ *target, int fd)
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
	static t_list	list;
	t_node_			*target;
	size_t			result_len;
	ssize_t			byte;

	if (BUFFER_SIZE <= 0)
		return (0);
	target = find_node(&list, fd, 1);
	if (target == 0)
		return (0);
	while (1)
	{
		result_len = ft_strchr(target->data, '\n');
		if (result_len > 0)
			return (get_result(&list, target, result_len, 0));
		byte = read_buf(target, fd);
		if (byte <= 0)
			return (get_last(&list, target, byte));
	}
}

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

// 	if (byte <= 0)
// 		return (0);
// 	s1_len = 0;
// 	while (s1 && s1[s1_len] != '\0')
// 		++s1_len;
// 	new_str = (char *)malloc(s1_len + byte + 1);
// 	if (new_str == 0)
// 		return (0);
// 	ft_strncpy(new_str, s1, s1_len);
// 	ft_strncpy(new_str + s1_len, s2, byte);
// 	return (new_str);
// }

// t_node_	*find_node(t_list *list, int fd, int check)
// {
// 	t_node_	*node;

// 	if (BUFFER_SIZE <= 0)
// 		return (0);
// 	node = list->head;
// 	while (node != 0)
// 	{
// 		if (node->fd == fd)
// 			return (node);
// 		node = node->next_node;
// 	}
// 	if (check == 1)
// 	{
// 		node = push_back(list, fd);
// 		if (node == 0)
// 			return (0);
// 		return (node);
// 	}
// 	return (0);
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

// void	delete_node(t_list *list, t_node_ *target)
// {
// 	if (target == 0)
// 		return ;
// 	if (target->prev_node != 0)
// 		target->prev_node->next_node = target->next_node;
// 	else
// 		list->head = target->next_node;
// 	if (target->next_node != 0)
// 		target->next_node->prev_node = target->prev_node;
// 	else
// 		list->tail = target->prev_node;
// 	//free(target->data);
// 	free(target);
// }

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
// 	int fd = open("t_newline.txt", O_RDONLY);
// 	printf("fd = %d\n", fd);

// 	print_line(fd);	// h
// 	print_line(fd);	// w
// 	print_line(fd);	// m
// 	print_line(fd);	// n
// 	print_line(fd);	// i

// 	print_line(fd);	// k
// 	print_line(fd);	// ^
// 	print_line(fd);
// 	print_line(fd);
// 	print_line(fd);
// }