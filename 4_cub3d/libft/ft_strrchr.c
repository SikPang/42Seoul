/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:23:10 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/03 00:55:54 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// NULL

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;
	char	cc;

	cc = (char)c;
	loc = NULL;
	while (*s != '\0')
	{
		if (*s == cc)
			loc = (char *)s;
		s++;
	}
	if (loc != NULL)
		return (loc);
	if (cc == '\0')
		return ((char *)s);
	return (NULL);
}
