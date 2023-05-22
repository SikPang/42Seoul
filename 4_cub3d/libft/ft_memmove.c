/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:51:42 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 00:59:29 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// size_t

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*uc_dst;
	const unsigned char	*uc_src;

	if (dst < src)
	{
		uc_dst = (unsigned char *)dst;
		uc_src = (const unsigned char *)src;
		while (len-- > 0)
		{
			(*uc_dst++) = (*uc_src++);
		}
	}
	else if (dst > src)
	{
		uc_dst = (unsigned char *)dst + len - 1;
		uc_src = (const unsigned char *)src + len - 1;
		while (len-- > 0)
		{
			(*uc_dst--) = (*uc_src--);
		}
	}
	return (dst);
}
