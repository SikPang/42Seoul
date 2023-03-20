/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:28:04 by sokwon            #+#    #+#             */
/*   Updated: 2022/11/25 12:06:50 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// size_t, NULL

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc_s;
	unsigned char	uc_c;

	uc_s = (unsigned char *)s;
	uc_c = (unsigned char)c;
	while (n-- > 0)
	{
		if (*uc_s == uc_c)
			return (uc_s);
		uc_s++;
	}
	return (NULL);
}
