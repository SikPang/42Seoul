/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:48:41 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 16:00:08 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;
	size_t	total;
	size_t	temp;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	temp = 0;
	while (temp < s1_len)
	{
		new_str[temp] = s1[temp];
		++temp;
	}
	total = temp;
	temp = 0;
	while (temp < s1_len)
	{
		new_str[temp + total] = s1[temp];
		++temp;
	}
	return (new_str);
}
