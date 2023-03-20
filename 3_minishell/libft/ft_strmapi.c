/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:19:40 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 16:11:06 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlen(), ft_calloc()
#include <stdlib.h>	// NULL, malloc()

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	idx;

	dst = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	idx = 0;
	while (s[idx] != '\0')
	{
		dst[idx] = f(idx, s[idx]);
		idx++;
	}
	return (dst);
}
