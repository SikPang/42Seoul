/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:24:01 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 13:58:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break;
		++i;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char *c1 = "abcdefg";
// 	char *c2 = "abcdefg";
// 	char *c3 = "abcdef";

// 	printf("%d %d %d\n", ft_memcmp(c1, c2, 8), ft_memcmp(c1, c3, 8)
// 		, ft_memcmp(c3, c1, 7));
// 	printf("%d %d %d\n", memcmp(c1, c2, 8), memcmp(c1, c3, 8)
// 		, memcmp(c3, c1, 7));
// }