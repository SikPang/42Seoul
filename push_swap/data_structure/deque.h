/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:54:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/07 22:36:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_deque
{
	char	**arr;
	int		capacity;
	int		size;
	int		head;
	int		tail;
}	t_deque;

void	init_deque(t_deque *deque, int size);
void	push_front(t_deque *deque, char *data);
void	push_back(t_deque *deque, char *data);
char	*pop_front(t_deque *deque);
char	*pop_back(t_deque *deque);

#endif