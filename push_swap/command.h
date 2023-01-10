/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:59:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/10 18:04:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "./data_structure/deque.h"
# include "./data_structure/queue.h"

void	c_swap(t_deque *deq1, t_deque *deq2, char chk, t_queue *que);
void	c_push(t_deque *dest, t_deque *src, char chk, t_queue *que);
void	c_rotate(t_deque *deq1, t_deque *deq2, char chk, t_queue *que);
void	c_reverse_rotate(t_deque *deq1, t_deque *deq2, char chk, t_queue *que);
void	print_commands(t_queue *que);

#endif