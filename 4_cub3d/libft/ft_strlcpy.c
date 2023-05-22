/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:51:21 by sokwon            #+#    #+#             */
/*   Updated: 2022/11/23 23:02:57 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlen()
#include <stddef.h>	// size_t

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	while (idx + 1 < dstsize && src[idx] != '\0')
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize > 0)
		dst[idx] = '\0';
	return (ft_strlen(src));
}
