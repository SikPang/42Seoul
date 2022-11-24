/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:32:36 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/24 17:16:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len != 0 && s_len - 1 < start)
		return ((char *)ft_calloc(1, sizeof(char)));
	new_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (new_str == (char *)0)
		return ((char *)0);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i + start];
		++i;
	}
	return (new_str);
}

// #include <stdio.h>
// int main()
// {
// 	char *str = "abcde";
// 	printf("%s", ft_substr(str, 0, 0));
// }