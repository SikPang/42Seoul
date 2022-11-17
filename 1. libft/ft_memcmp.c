/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:24:01 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 19:55:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		++i;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char *c1 = "abcdefghij";
// 	char *c2 = "abcdefgxyz";
// 	char *c3 = "abcdef";

// 	printf("%d %d %d\n", ft_memcmp(c1, c2, 7), ft_memcmp(c1, c3, 8)
// 		, ft_memcmp(c3, c1, 7));
// 	printf("%d %d %d\n", memcmp(c1, c2, 7), memcmp(c1, c3, 8)
// 		, memcmp(c3, c1, 7));
// }