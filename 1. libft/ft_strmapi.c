/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:00:50 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 20:58:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*new_str;

	s_len = ft_strlen(s);
	i = 0;
	new_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (new_str == (char *)0)
		return ((char *)0);
	new_str[s_len] = '\0';
	while (i < s_len)
	{
		new_str[i] = f(i, s[i]);
		++i;
	}
	return (new_str);
}
