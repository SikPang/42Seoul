/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:27:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 20:35:21 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

static int	get_index(char c, char *hex)
{
	int		i;
	int		j;
	
	j = 0;
	while (hex[j] != '\0')
	{
		if (c == hex[j])
			return (j);
		++j;
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
