/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:25:29 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 14:52:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(src);
	if (size == 0)
		return (count);
	i = 0;
	while (src[i] != '\0')
	{
		if (size == 1)
		{
			dest[i] = '\0';
			break ;
		}
		dest[i] = src[i];
		++i;
		--size;
	}
	if (dest[i] != '\0')
		dest[i] = '\0';
	return (count);
}
