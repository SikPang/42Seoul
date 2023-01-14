/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:16:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/14 17:17:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../data_structure/deque.h"
# include "../data_structure/queue.h"

int		*radix_sort(t_queue *que);
void	mini_sort(t_queue *que_a);
void	small_sort(t_queue *args);
void	main_sort(t_deque *deq_a, t_deque *deq_b);

#endif
