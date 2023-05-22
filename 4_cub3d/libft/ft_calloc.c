/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:13:27 by sokwon            #+#    #+#             */
/*   Updated: 2023/05/09 16:46:15 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// size_t, NULL, malloc()

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			bytes;
	size_t			idx;

	bytes = count * size;
	result = (unsigned char *)malloc(bytes);
	if (result == NULL)
		error_and_exit();
	idx = 0;
	while (idx < bytes)
		result[idx++] = '\0';
	return ((void *)result);
}
