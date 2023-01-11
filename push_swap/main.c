/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:34:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 20:52:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <unistd.h>
#include "push_swap.h"
#include "radix_sort.h"
#include "./data_structure/deque.h"
#include "./data_structure/queue.h"
#include "./utility/utility.h"

#include <stdio.h>
static void	convert_push(t_queue *que, t_deque *deq)
{
	t_node	*temp;
	int		idx;

	temp = que->head;
	idx = 0;
	while (que->max > 0)
	{
		que->max /= CONVERT_NUM;
		++deq->data_len;
	}
	if (deq->data_len == 0)
		deq->data_len = 1;
	while (temp != 0)
	{
		push_front(deq, convert(temp->data, deq->data_len));
		if (deq->arr[deq->head] == 0)
		{
			clean_queue(que);
			clean_deque(deq);
			exit(1);
		}
		++idx;
		temp = temp->next_node;
	}
}

static void	normalize(int *arr, int size, t_queue *que)
{
	t_node	*temp;
	int		j;

	temp = que->head;
	while (temp != 0)
	{
		j = 0;
		while (j < size)
		{
			if (temp->data == arr[j])
			{
				temp->data = j;
				if (j > que->max)
				que->max = j;
				break ;
			}
			++j;
		}
		temp = temp->next_node;
	}
}

static void	check_duplicate(int *arr, int size, t_queue *que)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			//write(2, "Error\n", 6);
			printf("Error : duplicated argument\n");
			clean_queue(que);
			free(arr);
			exit(1);
		}
		++i;
	}
}

static void	get_args(int ac, char **av, t_queue *que)
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
			push(que, ft_atoi(strs[j], que));
			free(strs[j]);
			++j;
		}
		free(strs);
		++i;
	}
}

int main(int ac, char *av[])
{
	t_queue	args;
	t_deque	deq_a;
	t_deque	deq_b;
	int		*sorted_arr;

	init_queue(&args);
	get_args(ac, av, &args);
	sorted_arr = radix_sort(&args);
	check_duplicate(sorted_arr, args.size, &args);
	normalize(sorted_arr, args.size, &args);
	free(sorted_arr);
	init_deque(&deq_a, args.size);
	convert_push(&args, &deq_a);
	init_deque(&deq_b, args.size);
	push_swap(&deq_a, &deq_b);


	// int a = args.size;
	// printf("\nSorted : ");
	// for (int i=0; i<a; ++i)
	// 	printf("%d ", sorted_arr[i]);

	// printf("\n\nA : ");
	// while (deq_a.size > 0)
	// {
	// 	char *cc = pop_back(&deq_a);
	// 	printf("%s ", cc);
	// 	free(cc);
	// }
	// printf("\n\nB : ");
	// while (deq_b.size > 0)
	// {
	// 	char *cc = pop_back(&deq_b);
	// 	printf("%s ", cc);
	// 	free(cc);
	// }
	// printf("\n");
	
	clean_queue(&args);
	clean_deque(&deq_a);
	clean_deque(&deq_b);

	return (0);
}
