/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:34:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/09 16:42:16 by kwsong           ###   ########.fr       */
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
		que->max /= 3;
		++deq->data_len;
	}
	while (temp != 0)
	{
		push_front(deq, convert(temp->data, deq->data_len));
		if (deq->arr[idx] == 0)
		{
			clean_queue(que);
			clean_deque(deq);
			exit(1);
		}
		// for (int i=0; i<deq->size; ++i)
		// 	printf("%d : %s ", i, deq->arr[i]);
		// printf("\n");
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

static void	push_args(int ac, char **av, t_queue *que)
{
	char	**strs;
	int		data;
	int		i;
	int		j;
	
	i = 1;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		j = 0;
		while (strs[j])
		{
			data = ft_atoi(strs[j], que);
			push(que, data);
			if (data > que->max)
				que->max = data;
			++j;
		}
		++i;
	}
}

#include <stdio.h>
int main(int ac, char *av[])
{
	t_queue	queue;
	t_deque	deque_a;
	t_deque	deque_b;
	int		*sorted_arr;

	init_queue(&queue);
	push_args(ac, av, &queue);
	sorted_arr = radix_sort(&queue);
	check_duplicate(sorted_arr, queue.size, &queue);
	normalize(sorted_arr, queue.size, &queue);
	init_deque(&deque_a, queue.size);
	convert_push(&queue, &deque_a);
	init_deque(&deque_b, queue.size);
	//push_swap(&deque_a, &deque_b);

	// clean_queue(&queue);
	// free(deque_a.arr);
	// free(deque_b.arr);


	

	t_node *temp = queue.head;
	printf("\nNormalized : ");
	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next_node;
	}

	int a = queue.size;
	printf("\n\nSorted : ");
	for (int i=0; i<a; ++i)
		printf("%d ", sorted_arr[i]);
	printf("\n");

	printf("\n\nA : ");
	while (deque_a.size > 0)
		printf("%s ", pop_back(&deque_a));

	// printf("\n\nB : ");
	// while (deque_b.size > 0)
	// 	printf("%d ", pop_back(&deque_b));
	// printf("\n");
	
	return (0);
}
