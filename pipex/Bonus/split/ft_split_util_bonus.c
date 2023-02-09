/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_util_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:42:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/09 14:52:20 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_split_bonus.h"

void	check_quote(char c, int *is_quote)
{
	if (c == '\'')
	{
		if (*is_quote == 0)
			*is_quote = 1;
		else if (*is_quote == 1)
			*is_quote = 0;
		else if (*is_quote == 2)
			*is_quote = 3;
		else if (*is_quote == 3)
			*is_quote = 2;
	}
	else if (c == '\"')
	{
		if (*is_quote == 0)
			*is_quote = 2;
		else if (*is_quote == 2)
			*is_quote = 0;
		else if (*is_quote == 1)
			*is_quote = 3;
		else if (*is_quote == 3)
			*is_quote = 1;
	}
}
