/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:42:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/06 23:20:02 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utility.h"

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
