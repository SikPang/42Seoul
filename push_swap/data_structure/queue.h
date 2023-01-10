/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:30:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 16:27:06 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

enum commands
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_node
{
	struct s_node	*next_node;
	struct s_node	*prev_node;
	int				data;
}	t_node;

typedef struct s_queue
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		max;
}	t_queue;

void	init_queue(t_queue *queue);
void	push(t_queue *queue, int data);
int		pop(t_queue *queue);
void	clean_queue(t_queue *queue);
char	*get_front(t_deque *deque);
char	*get_back(t_deque *deque);

#endif