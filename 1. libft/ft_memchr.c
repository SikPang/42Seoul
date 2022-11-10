/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:53:51 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 14:22:48 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == c)
			return ((void *)(s + i));
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
// 	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 	int *result = (int *)ft_memchr(arr, 2, 10);
// 	int *result2 = (int *)memchr(arr, 2, 10);

// 	printf("%s ", (char *)ft_memchr(str, '2', 10));
// 	printf("%s ", (char *)ft_memchr(str2, 'f', 10));
// 	for (int i=0; i<5; ++i)
// 		printf("%d", result[i]);
// 	printf("\n");
// 	printf("%s ", (char *)memchr(str, '2', 10));
// 	printf("%s ", (char *)memchr(str2, 'f', 10));
// 	for (int i=0; i<5; ++i)
// 		printf("%d", result2[i]);
// }