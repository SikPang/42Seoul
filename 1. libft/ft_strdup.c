/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:32:20 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 19:06:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*arr;

	i = 0;
	while (src[i] != '\0')
		++i;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (arr == 0)
		return (0);
	ft_strcpy(arr, src);
	return (arr);
}
