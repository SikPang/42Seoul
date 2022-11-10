/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:20:21 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 15:01:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char 	*temp;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			temp = ((char *)(s + i));
		++i;
	}
	if (s[i] == c)
			temp = ((char *)(s + i));
	return (temp);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[10] = "123426729";
// 	char str2[10] = "abfdefgfi";

// 	printf("%s ", ft_strrchr(str, '2'));
// 	printf("%s\n", ft_strrchr(str2, 'f'));
// 	printf("%s ", strrchr(str, '2'));
// 	printf("%s\n", strrchr(str2, 'f'));
// }