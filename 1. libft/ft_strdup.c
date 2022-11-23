/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:32:20 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 17:28:15 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*arr;

	i = 0;
	while (src[i] != '\0')
		++i;
	arr = (char *)calloc(i + 1, sizeof(char));
	if (arr == 0)
		return (0);
	ft_memcpy(arr, src, i);
	return (arr);
}
