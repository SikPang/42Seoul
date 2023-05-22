/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:10:19 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 16:54:31 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// size_t

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*uchar_dst;
	const unsigned char	*uchar_src;

	if (dst == src)
		return (dst);
	uchar_dst = (unsigned char *)dst;
	uchar_src = (const unsigned char *)src;
	while (n-- > 0)
	{
		*(uchar_dst++) = *(uchar_src++);
	}
	return (dst);
}
