/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:16:19 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/03 00:58:45 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_calloc(), ft_strlcpy()
#include <stdlib.h>	// NULL, size_t, malloc()

_Bool	ft_is_in_strset(const char c, const char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*end;
	size_t		len_trim;
	char		*dst;

	end = s1;
	while (*end != '\0')
		end++;
	while (ft_is_in_strset(*s1, set))
		s1++;
	if (s1 != end)
	{
		while (ft_is_in_strset(*(end - 1), set))
			end--;
	}
	len_trim = end - s1;
	dst = ft_substr(s1, 0, len_trim);
	return (dst);
}
