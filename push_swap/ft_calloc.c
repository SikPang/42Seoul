/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:34:02 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 19:28:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*new_mem;
	size_t	total;
	size_t	i;

	total = nelem * elsize;
	new_mem = malloc(total);
	if (new_mem == (void *)0)
		return ((void *)0);
	i = 0;
	while (i < total)
	{
		((unsigned char *)new_mem)[i] = 0;
		++i;
	}
	return (new_mem);
}
