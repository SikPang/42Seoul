/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:30:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 16:01:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_node
{
	struct s_node	*next_node;
	struct s_node	*prev_node;
	int				data;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_list;

typedef struct s_lnode
{
	struct s_lnode	*next_node;
	struct s_lnode	*prev_node;
	t_list			data;
}	t_lnode;

typedef struct s_llist
{
	t_lnode	*head;
	t_lnode	*tail;
	int		size;
}	t_llist;

void	init_list(t_list *queue);
void	clean_list(t_list *queue);
void	push(t_list *queue, int data);
int		pop(t_list *queue);
t_node	*erase(t_list *que, t_node *target);

#endif