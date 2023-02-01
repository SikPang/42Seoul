/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:27:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/01 14:13:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility_bonus.h"

static int	get_index(char c, char *hex)
{
	int		i;
	
	i = 0;
	while (hex[i] != '\0')
	{
		if (c == hex[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoh(char *str)
{
	unsigned int	num;
	char			*hex;
	int				index;
	int				i;

	hex = "0123456789ABCDEF0123456789abcdef";
	i = 0;
	num = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		index = get_index(str[i], hex);
		if (index == -1)
			error_exit();
		num = num * 16 + index % 16;
		++i;
	}
	return (num);
}
