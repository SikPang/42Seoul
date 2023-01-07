/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:54:57 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/30 17:24:15 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_deque
{
	int	*arr;
	int	capacity;
	int size;
	int	head;
	int	tail;
}	t_deque;

void	init_deque(t_deque *deque, int size);
void	push_front(t_deque *deque, int data);
void	push_back(t_deque *deque, int data);
int		pop_front(t_deque *deque);
int		pop_back(t_deque *deque);

#endif