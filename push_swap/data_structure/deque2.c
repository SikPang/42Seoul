/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:40:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/09 16:12:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"

void	clean_deque(t_deque *deque)
{
	int	i;

	i = 0;
	while (i < deque->size)
	{
		free(deque->arr[i]);
		++i;
	}
}
