/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:39 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 14:55:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	check_equal(char *str, char *to_find, int i, size_t to_find_len)
{
	size_t	find_index;

	find_index = 0;
	while (to_find[find_index] != '\0' && str[i] == to_find[find_index])
	{
		++find_index;
		++i;
	}
	if (find_index == to_find_len)
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
		return (str);
	i = 0;
	while (i < len)
	{
		if (str[i] == to_find[0])
		{
			if (check_equal(str, to_find, i, to_find_len))
				return (str + i);
		}
		++i;
	}
	return (0);
}