/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:27:51 by sokwon            #+#    #+#             */
/*   Updated: 2022/11/23 22:52:56 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// size_t

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uchar_b;

	uchar_b = (unsigned char *)b;
	while (len-- > 0)
	{
		(*uchar_b) = (unsigned char)c;
		uchar_b++;
	}
	return (b);
}
