/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:16:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/07 19:10:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./data_structure/deque.h"

void	push_swap(t_deque *deque1, t_deque *deque2);
void	c_swap(t_deque *deque1, t_deque *deque2, char check);
void	c_push(t_deque *dest, t_deque *src, char check);
void	c_rotate(t_deque *deque1, t_deque *deque2, char check);
void	c_reverse_rotate(t_deque *deque1, t_deque *deque2, char check);

#endif