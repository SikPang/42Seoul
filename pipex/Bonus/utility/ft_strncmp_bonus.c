/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:05:26 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/03 20:14:14 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		if (n == 1)
			return (0);
		++i;
		--n;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
