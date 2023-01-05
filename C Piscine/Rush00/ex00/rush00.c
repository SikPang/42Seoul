/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuko <seuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:21:39 by seuko             #+#    #+#             */
/*   Updated: 2022/10/01 15:32:48 by seuko            ###   ########.fr       */
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
		if (width == 1 && (height == y || height == 1))
			ft_putchar('o');
		else if (width == x && (height == y || height == 1))
			ft_putchar('o');
		else if (height == 1 || height == y)
			ft_putchar('-');
		else if (width == 1 || width == x)
			ft_putchar('|');
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
