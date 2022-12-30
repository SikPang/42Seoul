/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:10:04 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/30 14:11:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "deque.h"
#include "./utility/utility.h"

static void	push_args(int ac, char **av, t_deque *deque)
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
			push_back(deque, ft_atoi(strs[j], deque));
			++j;
		}
		++i;
	}
}

static int	get_size(int ac, char **av)
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
		if (j != 0 && av[i][j - 1] != ' ')
			++size;
		
		++i;
	}
	return (size);
}

int main(int ac, char *av[])
{
	t_deque	deque_a;
	t_deque	deque_b;
	char	size;

	size = get_size(ac, av);
	init_deque(&deque_a, size);
	push_args(ac, av, &deque_a);
	init_deque(&deque_b, size);
	// push_swap()

	// for (int i=0; i<deque_a.size; ++i)
	// 	printf("%d ", pop_back(&deque_a));
	return (0);
}