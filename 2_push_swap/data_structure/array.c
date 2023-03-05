/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:39:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/13 20:46:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"
#include "../utility/utility.h"

void	init_arr(t_array *arr, int size)
{
	arr->arr = (int *)malloc(size * sizeof(int));
	if (arr->arr == 0)
		error_exit();
	arr->size = size;
	arr->max_cnt = 0;
}
