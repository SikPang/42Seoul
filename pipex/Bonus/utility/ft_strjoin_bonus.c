/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:48:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/08 17:01:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utility_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 2);
	if (new_str == (char *)0)
		return ((char *)0);
	new_str[s1_len + s2_len + 1] = '\0';
	ft_strncpy(new_str, s1, s1_len);
	new_str[s1_len] = '/';
	ft_strncpy(new_str + s1_len + 1, s2, s2_len);
	return (new_str);
}
