/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:23:58 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 15:31:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		++i;
	}
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char str1[] = "aaaaaaaaaaaa";
//     ft_bzero(str1, sizeof(char) * 3);
//     char str2[] = "aaaaaaaaaaaa";
//     bzero(str2, sizeof(char) * 3);

// 	int arr1[10]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     ft_bzero(arr1, sizeof(int) * 3);
//     int arr2[10]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     bzero(arr2, sizeof(int) * 3);

//     printf("%s ", str1);
// 	printf("%c ", str1[3]);
// 	for (int i=0; i<10; ++i)
// 		printf("%d", arr1[i]);
// 	printf("\n");
//     printf("%s ", str2);
// 	printf("%c ", str2[3]);
// 	for (int i=0; i<10; ++i)
// 		printf("%d", arr2[i]);
// }