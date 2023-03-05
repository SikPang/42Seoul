/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:25:29 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 19:05:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			return (count);
		}
		dest[i] = src[i];
		++i;
		--size;
	}
	dest[i] = '\0';
	return (count);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char dest[5];
// 	char src[5] = "abcd";
// 	ft_strlcpy(dest, src, 6);
// 	printf("%s", dest);
// }