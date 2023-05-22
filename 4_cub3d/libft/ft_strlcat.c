/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:15:22 by sokwon            #+#    #+#             */
/*   Updated: 2022/11/25 12:14:48 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlen()
#include <stddef.h>	// size_t

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (*dst != '\0')
	{
		dst++;
		dstsize--;
	}
	while (dstsize-- > 1 && *src != '\0')
		*(dst++) = *(src++);
	*dst = '\0';
	return (dst_len + src_len);
}
