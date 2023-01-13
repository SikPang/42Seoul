/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:23:50 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/13 20:48:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utility.h"

char	*convert(int data, int size)
{
	char	*converted;
	int		i;

	i = 0;
	converted = (char *)malloc(size + 1);
	if (converted == 0)
		error_exit();
	while (i < size)
	{
		converted[i] = '0';
		++i;
	}
	converted[i] = '\0';
	while (data > 0)
	{
		converted[size - 1] = data % CONVERT_NUM + '0';
		data /= CONVERT_NUM;
		--size;
	}
	return (converted);
}
