/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:09:36 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 17:00:36 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_calloc(), ft_strlen()
#include <stdlib.h>	// malloc(), NULL, size_t

/**
 * @exception s is NULL
 * @exception start is out of string s.
 * @exception malloc failure.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_substr;
	char	*substr;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start)
		return (ft_calloc(1, sizeof(char)));
	if (len_s - start <= len)
		len_substr = len_s - start;
	else
		len_substr = len;
	substr = (char *)ft_calloc(len_substr + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, s + start, len_substr);
	substr[len_substr] = '\0';
	return (substr);
}
