/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:39 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/13 17:50:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	check_equal(const char *str, const char *to_find
, int i, size_t len)
{
	size_t	find_index;
	size_t	to_find_len;

	while (to_find[to_find_len] != '\0')
		++to_find_len;
	find_index = 0;
	while (to_find[find_index] != '\0' && str[i] == to_find[find_index])
	{
		++find_index;
		++i;
	}
	if (find_index == to_find_len && i <= len)
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char	*str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	to_find_len;

	to_find_len = 0;
	while (to_find[to_find_len] != '\0')
		++to_find_len;
	if (to_find_len == 0)
		return ((char *)str);
	i = 0;
	while (i < len)
	{
		if (str[i] == to_find[0])
		{
			if (check_equal(str, to_find, i, len))
				return ((char *)(str + i));
		}
		++i;
	}
	return ((char *)0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *str = "abcdefg";
// 	char *to_find = "def";

// 	printf("%s %s\n", ft_strnstr(str, to_find, 4), ft_strnstr(str, to_find, 6));
// 	printf("%s %s\n", strnstr(str, to_find, 4), strnstr(str, to_find, 6));
// }