/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:38:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/03 11:18:01 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		perror_and_exit(error_malloc);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, t_vector2 data)
{
	t_snode	*new_node;

	new_node = (t_snode *)malloc(sizeof(t_snode));
	if (new_node == NULL)
		perror_and_exit(error_malloc);
	new_node->data = data;
	new_node->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new_node;
		new_node->prev = NULL;
	}
	else
	{
		stack->top->next = new_node;
		new_node->prev = stack->top;
		stack->top = new_node;
	}
	++(stack->size);
}

t_vector2	pop(t_stack *stack)
{
	t_snode		*temp;
	t_vector2	result;

	result = stack->top->data;
	temp = stack->top;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		stack->top->prev->next = NULL;
		stack->top = stack->top->prev;
	}
	free(temp);
	--(stack->size);
	return (result);
}

void	destroy_stack(t_stack **stack_ref)
{
	if (stack_ref == NULL || *stack_ref == NULL)
		return ;
	while ((*stack_ref)->size > 0)
		pop(*stack_ref);
	free(*stack_ref);
	*stack_ref = NULL;
}
