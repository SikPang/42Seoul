/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:11:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 14:37:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src && n > 0)
	{
		n -= 1;
		while (1)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			if (n == 0)
				break ;
			--n;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str1[10] = "1234567890";
// 	char str2[10] = "zzzzzzzzz";
// 	char str3[10] = "1234567890";
// 	char str4[10] = "zzzzzzzzz";
// 	char *result1 = ft_memmove(str1 + 1, str1, sizeof(char) * 9);
// 	char *result2 = memmove(str3 + 1, str3, sizeof(char) * 9);

// 	int arr1[10] = {};
// 	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 	int arr3[10] = {};
// 	int arr4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 	int *result3 = ft_memmove(arr2 + 1, arr2, sizeof(int) * 10);
// 	int *result4 = memmove(arr4 + 1, arr4, sizeof(int) * 10);

// 	printf("%s ", result1);
// 	for (int i = 0; i < 10; ++i)
// 		printf("%d", result3[i]);

// 	printf("\n");
// 	printf("%s ", result2);
// 	for (int i = 0; i < 10; ++i)
// 		printf("%d", result4[i]);
// }