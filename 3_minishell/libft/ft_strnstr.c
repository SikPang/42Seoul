/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:48:28 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 16:27:48 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// size_t, NULL

/**
 * Compare the string in s1 until s2 encounters a null character.
 * @param s1 Substring of the haystack.
 * @param s2 String of the needle.
 * @param len Length of the s1.
 * @return 0: if not match, 1: if match, -1: if not match and when the s1 ends.
 */
static int	ft_is_matched(const char *s1, const char *s2, size_t len)
{
	while (*s2 != '\0' && *s1 != '\0' && len > 0 && *s1 == *s2)
	{
		s1++;
		s2++;
		len--;
	}
	if (*s2 == '\0')
		return (1);
	if (*s1 == '\0' || len == 0)
		return (-1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	flag_match;

	while (1)
	{
		flag_match = ft_is_matched(haystack, needle, len);
		if (flag_match == 1)
			return ((char *)haystack);
		else if (flag_match == -1)
			break ;
		if (*(++haystack) == '\0' || --len == 0)
			break ;
	}
	return (NULL);
}
