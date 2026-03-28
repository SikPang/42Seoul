/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:26:52 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/09 17:27:09 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>

void	rush(t_set *set);

int	ft_atoi(char *number, t_set *set, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			(*set).num[j][k] = (int)number[i] - '0';
			++i;
			++k;
		}
		++j;
	}
	return (0);
}

int	is_space(char *str, int i)
{
	if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
		return (1);
	return (0);
}

int	check_end(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_split(char *str, char *number, int i, int j)
{
	while (str[i] && j < 16)
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			if (is_space(str, i) && str[i] >= '1' && str[i] <= '4')
			{
				number[j] = str[i];
				j++;
				i++;
			}
			else
				return (0);
		}
	}
	if (check_end(str, i) && j == 16)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	number[16];
	t_set	set;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_split(argv[1], number, 0, 0))
	{
		ft_atoi(number, &set, 0);
		rush(&set);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
