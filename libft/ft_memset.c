/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:38:18 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 21:31:03 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		++i;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char str1[] = "aaaaaaaaaaaa";
//     char *result1 = ft_memset(str1, 'b', sizeof(char) * 3);
//     char str2[] = "aaaaaaaaaaaa";
//     char *result2 = memset(str2, 'b', sizeof(char) * 3);

// 	int arr1[10]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     int *result3 = ft_memset(arr1, 0, sizeof(int) * 3);
//     int arr2[10]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     int *result4 = memset(arr2, 0, sizeof(int) * 3);

//     printf("%s ", result1);
// 	for (int i=0; i<10; ++i)
// 		printf("%d", result3[i]);
// 	printf("\n");
//     printf("%s ", result2);
// 	for (int i=0; i<10; ++i)
// 		printf("%d", result4[i]);
// }