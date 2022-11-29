/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:11:32 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 20:10:14 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
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
// 	char str1[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQR
//			STUVWXYZ0123456789!@#$%^&*()_+{}[]zyxwvutsrqponmlkjihg";
// 	//char str2[10] = "zzzzzzzzz";
// 	char str3[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQR
//			STUVWXYZ0123456789!@#$%^&*()_+{}[]zyxwvutsrqponmlkjihg";
// 	//char str4[10] = "zzzzzzzzz";
// 	char *result1 = ft_memmove(str1, str1+99, sizeof(char) * 1);
// 	char *result2 = memmove(str3, str3+99, sizeof(char) * 1);

// 	//int arr1[10] = {};
// 	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 	//int arr3[10] = {};
// 	int arr4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 	int *result3 = ft_memmove(arr2, arr2+1, 1);
// 	int *result4 = memmove(arr4, arr4+1, 1);

// 	for(int i=0; i<100; ++i)
// 		printf("%c", result1[i]);
// 	//printf("%s ", result1);
// 	//for (int i = 0; i < 10; ++i)
// 	//	printf("%d", result3[i]);

// 	printf("\n");
// 	for(int i=0; i<100; ++i)
// 		printf("%c", result2[i]);
// 	//printf("%s ", result2);
// 	//for (int i = 0; i < 10; ++i)
// 	//	printf("%d", result4[i]);
// }