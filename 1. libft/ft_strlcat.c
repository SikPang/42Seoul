/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:35:49 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 19:05:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	i;
	size_t	j;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (size < dest_length)
		return (size + src_length);
	i = 0;
	j = dest_length;
	size -= dest_length;
	while (src[i] != '\0')
	{
		if (size <= 1)
			break ;
		dest[j] = src[i];
		++j;
		++i;
		--size;
	}
	dest[j] = '\0';
	return (dest_length + src_length);
}
