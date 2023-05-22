/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:34:57 by sokwon            #+#    #+#             */
/*   Updated: 2022/11/24 18:48:32 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlen(), ft_strlcat()
#include <stdlib.h>	// NULL, malloc()

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	dst_size;

	dst_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)ft_calloc(sizeof(char), dst_size);
	if (dst == NULL)
		return (NULL);
	ft_strlcat(dst, s1, dst_size);
	ft_strlcat(dst, s2, dst_size);
	return (dst);
}
