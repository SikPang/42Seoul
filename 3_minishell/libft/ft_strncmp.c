/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:27:10 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 01:04:41 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// size_t

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;
	size_t				idx;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n && (uc_s1[idx] != '\0' || uc_s2[idx] != '\0'))
	{
		if (uc_s1[idx] != uc_s2[idx])
			return ((int)uc_s1[idx] - uc_s2[idx]);
		idx++;
	}
	return (0);
}
