/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:16:10 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/15 18:40:55 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"

void	swap(t_deque *deque1, t_deque *deque2, char check);
void	push(t_deque *dest, t_deque *src, char check);
void	rotate(t_deque *deque1, t_deque *deque2, char check);
void	reverse_rotate(t_deque *deque1, t_deque *deque2, char check);

#endif