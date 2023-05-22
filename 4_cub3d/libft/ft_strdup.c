/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:12 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/05 09:58:11 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlen(), ft_strlcpy()
#include <stdlib.h>	// size_t, NULL, malloc()

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	dst_size;

	dst_size = ft_strlen(s1) + 1;
	dst = (char *)malloc(sizeof(char) * dst_size);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, dst_size);
	return (dst);
}
