/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:34:44 by song              #+#    #+#             */
/*   Updated: 2022/12/05 18:20:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

// 1.	list를 순회하며 fd를 찾음, 해당 fd의 노드가 없으면 push_back
// 2.	해당 노드의 data에서 \n을 찾음
// 3-1.	\n가 있으면 \n까지 substr하여 반환, 종료
// 3-2.	\n이 없으면 read하여 buf 안에 \n이 있는지 탐색
// 4.	list의 data와 buf를 strjoin하여 list의 data에 삽입
// 5.	buf에 \n이 없으면 list의 data에 strjoin하고 3-2로 돌아가서 반복

char	*get_last(t_node_ *node, t_list *list, int fd)
{
	char	*result;
	size_t	data_len;

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

void	add_to_data(t_node_ *node, char *buf, ssize_t byte)
{
	char	*temp;

	if (byte == -1)
		return ;
	temp = node->data;
	node->data = ft_strjoin(node->data, buf, byte);
	free(temp);
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
	t_node_			*target_node;
	char			buf[BUFFER_SIZE];
	ssize_t			byte;
	ssize_t			new_line_index;

	target_node = find_node(&list, fd);
	byte = BUFFER_SIZE;
	while (1)
	{
		new_line_index = find_new_line(target_node);
		if (new_line_index >= 0 || (new_line_index == -1 && byte == 0))
			break ;
		byte = read(fd, buf, BUFFER_SIZE);
		if ((new_line_index == -2 && byte == 0) || byte == -1)
		{
			delete_node(&list, fd);
			return (0);
		}
		add_to_data(target_node, buf, byte);
	}
	if (new_line_index < 0)
		return (get_last(target_node, &list, fd));
	return (get_result(target_node, new_line_index));
}

/////////////////////

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

// 	print_line(4);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);

// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// }