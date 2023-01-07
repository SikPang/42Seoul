/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:34:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/07 17:54:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "push_swap.h"
#include "radix_sort.h"
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
			push_front(deque, ft_atoi(strs[j], deque));
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

#include <stdio.h>
int main(int ac, char *av[])
{
	t_deque	deque_a;
	t_deque	deque_b;
	int		*sorted_arr;
	int		size;

	size = get_size(ac, av);
	init_deque(&deque_a, size);
	push_args(ac, av, &deque_a);
	sorted_arr = radix_sort(&deque_a);
	init_deque(&deque_b, size);
	//push_swap(&deque_a, &deque_b);

	printf("\nA : %d\n", deque_a.size);
	while (deque_a.size > 0)
	 	printf("%d ", pop_back(&deque_a));

	// printf("\n\nSorted : ");
	// for (int i=0; i<a; ++i)
	//  	printf("%d ", sorted_arr[i]);

	printf("\n\nB : %d\n", deque_b.size);
	while (deque_b.size > 0)
		printf("%d ", pop_back(&deque_b));
	return (0);
}
