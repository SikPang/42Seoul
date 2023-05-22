/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:36:01 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 17:24:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

# include "error_handler_bonus.h"
# include "libft.h"
# include "info_bonus.h"

typedef struct s_snode
{
	struct s_snode	*prev;
	struct s_snode	*next;
	t_vector2		data;
}	t_snode;

typedef struct s_stack
{
	t_snode		*top;
	int			size;
}	t_stack;

t_stack		*init_stack(void);
void		push(t_stack *stack, t_vector2 data);
t_vector2	pop(t_stack *stack);
void		destroy_stack(t_stack **stack_ref);

#endif