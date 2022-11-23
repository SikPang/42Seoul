/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:32:36 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 15:57:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	new_str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i + start];
		++i;
	}
	return (new_str);
}
