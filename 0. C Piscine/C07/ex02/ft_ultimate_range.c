/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:34:11 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/16 00:57:13 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	long long	i;

	if (min >= max)
		return (0);
	size = (long long)max - (long long)min;
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		++min;
		++i;
	}
	return ((int)size);
}
