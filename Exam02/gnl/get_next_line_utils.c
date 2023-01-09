/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:18:39 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/09 20:00:16 by kwsong           ###   ########.fr       */
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
