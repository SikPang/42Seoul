/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:10:04 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/15 20:23:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "libft.h"
#include "ft_printf.h"

int	check_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

int	push_args(int ac, char **av, t_deque *deque)
{
	char	**strs;
	int		i;
	int		j;
	
	i = 1;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		j = 0;
		while (strs[j])
		{
			if (!check_valid(strs[j]))
				return (0);
			push_back(deque, ft_atoi(strs[j]));
			++j;
		}
		++i;
	}
	return (1);
}

int	get_size(int ac, char **av)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			++j;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == ' ' && av[i][j - 1] != ' ')
				++size;
			++j;
		}
		if (i != 0 && av[i][j - 1] != ' ')
			++size;
		++i;
	}
	return (size);
}

int main(int ac, char **av)
{
	t_deque	deque_a;
	t_deque	deque_b;
	char	size;

	size = get_size(ac, av);
	init_deque(&deque_a, size);
	init_deque(&deque_b, size);
	if (!push_args(ac, av, &deque_a))
	{
		free(deque_a.arr);
		free(deque_b.arr);
		ft_printf("Error\n");
		return (0);
	}
	// push_swap()
	return (0);
}