/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:54:35 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	uch;
	char			*hex;
	int				temp;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		uch = str[i];
		if (uch < 32 || uch >= 127)
		{
			write(1, "\\", 1);
			temp = hex[uch / 16];
			write(1, &temp, 1);
			temp = hex[uch % 16];
			write(1, &temp, 1);
		}
		else
			write(1, &uch, 1);
		++i;
	}
}
