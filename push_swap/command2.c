/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 20:55:55 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "command.h"

// static t_node *	remove_ra(t_node *cur, int pa_size)
// {
// 	t_node	*temp;
// 	int		i;

// 	i = 0;
// 	while (cur->data != RRA)
// 	{
// 		if (i++ < pa_size)
// 			cur->data = RRA;
// 		else if (cur->data == RA)
// 		{
// 			temp = cur->next_node;
// 			cur->prev_node->next_node = cur->next_node;
// 			cur->next_node->prev_node = cur->prev_node;
// 			free(cur);
// 			cur = temp;
// 		}
// 		cur = cur->next_node;
// 	}
// 	return (cur);
// }

// static int	get_pa_size(t_node *cur)
// {
// 	int	pa_size;
// 	int	ra_size;

// 	pa_size = 0;
// 	ra_size = 0;
// 	while (cur->data == RA && cur->next_node->data == RA)
// 	{
// 		++ra_size;
// 		cur = cur->next_node;
// 	}
// 	cur = cur->next_node;
// 	if (cur->data != PA)
// 		return (0);
// 	while (cur->data == PA && cur->next_node->data == PA)
// 	{
// 		++pa_size;
// 		cur = cur->next_node;
// 	}
// 	if (ra_size > pa_size)
// 		return (pa_size + 1);
// 	else
// 		return (0);
// }

// void	optimize_commands(t_queue *que)
// {
// 	t_node	*cur;
// 	int		pa_size;
// 	int		check;

// 	cur = que->head;
// 	check = 0;
// 	while (cur->next_node != 0)
// 	{
// 		if (cur->data == RRA && cur->next_node->data != RRA)
// 			check = 1;
// 		if (check == 1 && cur->data == RA && cur->next_node->data == RA)
// 		{
// 			pa_size = get_pa_size(cur);
// 			if (pa_size > 0)
// 				cur = remove_ra(cur, pa_size);
// 			check = 0;
// 		}
// 		cur = cur->next_node;
// 	}
// }

static void	print_commands2(int data)
{
	if (data == RA)
		write(1, "ra\n", 3);
	else if (data == RB)
		write(1, "rb\n", 3);
	else if (data == RR)
		write(1, "rr\n", 3);
	else if (data == RRA)
		write(1, "rra\n", 4);
	else if (data == RRB)
		write(1, "rrb\n", 4);
	else if (data == RRR)
		write(1, "rrr\n", 4);
}

void	print_commands(t_queue *que)
{
	t_node	*temp;
	t_node	*cur;

	cur = que->head;
	while (cur != 0)
	{
		if (cur->data == SA)
			write(1, "sa\n", 3);
		else if (cur->data == SB)
			write(1, "sb\n", 3);
		else if (cur->data == SS)
			write(1, "ss\n", 3);
		else if (cur->data == PA)
			write(1, "pa\n", 3);
		else if (cur->data == PB)
			write(1, "pb\n", 3);
		else
			print_commands2(cur->data);
		temp = cur->next_node;
		free(cur);
		cur = temp;
	}
}

