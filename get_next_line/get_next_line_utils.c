/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:52:04 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/02 16:18:36 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strncpy(char *dest, char *src, size_t start_index, size_t n)
{
	size_t	i;

	if (src == 0)
		return ;
	i = 0;
	while (n > 0)
	{
		dest[i + start_index] = src[i];
		++i;
		--n;
	}
	dest[i + start_index] = '\0';
	return ;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		new_str = (char *)malloc(1);
		new_str[0] = '\0';
		return (new_str);
	}
	if (s_len - start < len)
		len = s_len - start;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	new_str[len] = '\0';
	if (new_str == (char *)0)
		return ((char *)0);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i + start];
		++i;
	}
	return (new_str);
}
