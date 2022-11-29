/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:33:21 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 20:08:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char c1[10] = "";
//     char c2[10] = "zzzzzzzzz";
// 	char c3[10] = "";
//     char c4[10] = "zzzzzzzzz";
//     char *result1 = ft_memcpy(c1, c2, sizeof(char) * 5);
//     char *result2 = memcpy(c3, c4, sizeof(char) * 5);

// 	// vscode는 aaaaaghi, abcdeghi로 출력
//     char str1[10] = "abcdefghi";
//     char str2[10] = "zzzzzzzzz";
// 	char str3[10] = "abcdefghi";
//     char str4[10] = "zzzzzzzzz";
//     char *result3 = ft_memcpy(str1+1, str1, sizeof(char) * 5);
//     char *result4 = memcpy(str3+1, str3, sizeof(char) * 5);

// 	int arr1[10]= {};
//     int arr2[10]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
// 	int arr3[10]= {};
//     int arr4[10]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     int *result5 = ft_memcpy(arr1, arr2, sizeof(int) * 3);
//     int *result6 = memcpy(arr3, arr4, sizeof(int) * 3);

// 	printf("%s ", result1);
//     printf("%s ", result3);
// 	for (int i=0; i<10; ++i)
// 		printf("%d", result5[i]);

// 	printf("\n");
// 	printf("%s ", result2);
//     printf("%s ", result4);
// 	for (int i=0; i<10; ++i)
// 		printf("%d", result6[i]);
// }