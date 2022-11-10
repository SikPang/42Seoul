/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuko <seuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:26:43 by seuko             #+#    #+#             */
/*   Updated: 2022/10/01 15:33:27 by seuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	width;
	int	height;

	width = 1;
	height = 1;
	while (width <= x && height <= y)
	{
		if (width == 1 && height == 1)
			ft_putchar('/');
		else if ((width == 1 && height == y) || (width == x && height == 1))
			ft_putchar('\\');
		else if (width == x && height == y)
			ft_putchar('/');
		else if (height == 1 || height == y || width == 1 || width == x)
			ft_putchar('*');
		else
			ft_putchar(' ');
		width++;
		if (width == x + 1)
		{
			ft_putchar('\n');
			height++;
			width = 1;
		}
	}
}
