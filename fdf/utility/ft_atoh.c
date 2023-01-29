/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:27:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/29 17:22:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	ft_atoh(char *str)
{
	int		i;
	int		j;
	int		num;
	int		check;
	char	*hex;

	hex = "0123456789ABCDEF0123456789abcdef";
	i = 0;
	num = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		j = 0;
		check = 0;
		while (hex[j] != '\0')
		{
			if (str[i] == hex[j])
			{
				num = (num * 16) + (j % 16);
				check = 1;
			}
			++j;
		}
		if (check == 0)
			error_exit();
		++i;
	}
	return (num);
}
