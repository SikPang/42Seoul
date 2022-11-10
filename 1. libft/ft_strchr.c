/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:02:19 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 14:49:06 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		++i;
	}
	if (s[i] == c)
			return ((char *)(s + i));
	return ((char *)0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[10] = "123426729";
// 	char str2[10] = "abfdefgfi";

// 	printf("%s ", ft_strchr(str, '2'));
// 	printf("%s\n", ft_strchr(str2, 'f'));
// 	printf("%s ", strchr(str, '2'));
// 	printf("%s\n", strchr(str2, 'f'));
// }