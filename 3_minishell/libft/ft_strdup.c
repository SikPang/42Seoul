/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:12 by sokwon            #+#    #+#             */
/*   Updated: 2023/02/27 14:35:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlen(), ft_strlcpy()
#include <stdlib.h>	// size_t, NULL, malloc()

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	dst_size;

	if (s1 == NULL)
		return (NULL);
	dst_size = ft_strlen(s1) + 1;
	dst = (char *)malloc(sizeof(char) * dst_size);
	if (dst == NULL)
		ft_error(ERROR_MALLOC);
	ft_strlcpy(dst, s1, dst_size);
	return (dst);
}
