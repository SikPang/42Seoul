/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:54:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 18:05:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_deque
{
	char	**arr;
	int		capacity;
	int		size;
	int		front_size;
	int		back_size;
	int		head;
	int		tail;
	int		data_len;
}	t_deque;

void	init_deque(t_deque *deque, int size);
void	clean_deque(t_deque *deque);
void	push_front(t_deque *deque, char *data);
void	push_back(t_deque *deque, char *data);
char	*pop_front(t_deque *deque);
char	*pop_back(t_deque *deque);
char	*get_front(t_deque *deque);
char	*get_back(t_deque *deque);

#endif