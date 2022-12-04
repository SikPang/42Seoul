/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song <song@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:35:11 by song              #+#    #+#             */
/*   Updated: 2022/12/04 22:20:29 by song             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
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
