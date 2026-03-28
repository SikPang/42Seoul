/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:47:49 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 10:29:33 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>	//malloc(), free(), exit(), NULL
# include "ft_putstr.h"
# include "pm_mem.h"	//check_null_after_malloc()

# define IS_EMPTY -1

typedef struct s_queue	t_queue;

struct s_queue
{
	char	*circular_queue;
	int		front;
	int		rear;
	int		max_size;
	int		(*enque)(t_queue *this, char c);
	char	(*deque)(t_queue *this);
};

t_queue	*new_t_queue(int max_size);
void	del_t_queue(t_queue *this);
// output : false (if queue is full), true (else)
int		t_queue_enque(t_queue *this, char c);
// output : -1 (if queue is empty), element (else)
char	t_queue_deque(t_queue *this);

#endif
