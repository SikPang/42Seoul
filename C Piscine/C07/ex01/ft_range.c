/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:46:59 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/16 00:56:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*arr;
	long long	size;
	long long	i;

	if (min >= max)
		return (0);
	size = (long long)max - (long long)min;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == 0)
		return (0);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		++min;
		++i;
	}
	return (arr);
}
