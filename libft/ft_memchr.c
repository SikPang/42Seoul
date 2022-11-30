/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:53:51 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 21:55:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		++i;
	}
	return ((void *)0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[10] = "123426729";
// 	char str2[10] = "abfdefgfi";
// 	int arr[10] = {-49, 49, 1, -1, 0, 'e', 'f'};

// 	printf("%s ", (char *)ft_memchr(str, '2', 10));
// 	printf("%s ", (char *)ft_memchr(str2, 'f', 10));
// 	printf("%s", (char *)ft_memchr(arr, -1, 7));
// 	printf("\n");
// 	printf("%s ", (char *)memchr(str, '2', 10));
// 	printf("%s ", (char *)memchr(str2, 'f', 10));
// 	printf("%s", (char *)memchr(arr, -1, 7));
// }