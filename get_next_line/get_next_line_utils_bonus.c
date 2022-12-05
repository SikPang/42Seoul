/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:35:11 by song              #+#    #+#             */
/*   Updated: 2022/12/05 19:51:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char const *s1, char const *s2, ssize_t byte)
{
	size_t	s1_len;
	char	*new_str;

	if (s1 == 0)
	{
		new_str = (char *)malloc((byte + 1) * sizeof(char));
		if (new_str == 0)
			return (0);
		ft_strncpy(new_str, s2, byte);
		return (new_str);
	}
	s1_len = 0;
	while (s1[s1_len] != '\0')
		++s1_len;
	new_str = (char *)malloc((s1_len + byte + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	ft_strncpy(new_str, s1, s1_len);
	ft_strncpy(new_str + s1_len, s2, byte);
	return (new_str);
}

t_node_	*find_node(t_list *list, int fd, int check)
{
	t_node_	*node;

	node = list->head;
	while (node != 0)
	{
		if (node->fd == fd)
			return (node);
		node = node->next_node;
	}
	if (check == 1)
		return (push_back(list, fd));
	else
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

void	delete_node(t_list *list, int fd)
{
	t_node_	*node;

	node = find_node(list, fd, 0);
	if (node == 0)
		return ;
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
