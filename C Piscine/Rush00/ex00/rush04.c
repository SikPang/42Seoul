/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghoha <junghoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:05:04 by junghoha          #+#    #+#             */
/*   Updated: 2022/10/01 14:17:39 by junghoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	x_line;
	int	y_line;

	x_line = 1;
	y_line = 1;
	while (x_line <= x && y_line <= y)
	{
		if (x_line == 1 && y_line == 1)
			ft_putchar('A');
		else if ((x_line == x && y_line == 1) || (x_line == 1 && y_line == y))
			ft_putchar('C');
		else if (x_line == x && y_line == y)
			ft_putchar('A');
		else if (y_line == 1 || x_line == 1 || y_line == y || x_line == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		x_line++;
		if (x_line == (x + 1))
		{
			ft_putchar('\n');
			y_line++;
			x_line = 1;
		}
	}
}
