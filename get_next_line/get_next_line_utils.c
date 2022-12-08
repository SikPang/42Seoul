/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:18:39 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/08 13:18:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strchr(char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		++i;
	}
	if (c == '\0')
		return (i + 1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t byte)
{
	size_t	s1_len;
	char	*new_str;

	s1_len = 0;
	while (s1 && s1[s1_len] != '\0')
		++s1_len;
	new_str = (char *)malloc(s1_len + byte + 1);
	if (new_str == 0)
	{
		free(s2);
		return (0);
	}
	ft_strncpy(new_str, s1, s1_len);
	ft_strncpy(new_str + s1_len, s2, byte);
	return (new_str);
}

t_node_	*find_node(t_list *list, int fd, int check)
{
	t_node_	*node;

	if (BUFFER_SIZE <= 0)
		return (0);
	node = list->head;
	while (node != 0)
	{
		if (node->fd == fd)
			return (node);
		node = node->next_node;
	}
	if (check == 1)
	{
		node = push_back(list, fd);
		if (node == 0)
			return (0);
		return (node);
	}
	return (0);
}

t_node_	*push_back(t_list *list, int fd)
{
	t_node_	*new_node;
	t_node_	*cur_node;

	new_node = (t_node_ *)malloc(sizeof(t_node_));
	if (new_node == 0)
		return (0);
	new_node->prev_node = 0;
	new_node->next_node = 0;
	new_node->fd = fd;
	new_node->data = 0;
	if (list->head == 0)
	{
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

void	delete_node(t_list *list, t_node_ *target)
{
	if (target == 0)
		return ;
	if (target->prev_node != 0)
		target->prev_node->next_node = target->next_node;
	else
		list->head = target->next_node;
	if (target->next_node != 0)
		target->next_node->prev_node = target->prev_node;
	else
		list->tail = target->prev_node;
	free(target->data);
	free(target);
}
