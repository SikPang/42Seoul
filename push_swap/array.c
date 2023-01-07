/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:39:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/07 17:56:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <stdlib.h>

void	init_arr(t_array *arr, int size)
{
	arr->arr = (int *)malloc(size * sizeof(int));
	arr->size = size;
	arr->max_cnt = 0;
}
