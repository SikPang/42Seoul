/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:30:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 21:08:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_node
{
	struct s_node	*next_node;
	struct s_node	*prev_node;
	double			x;
	double			y;
	double			z;
	int				color;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
	double	max;
}	t_list;

typedef struct s_lnode
{
	struct s_lnode	*next_node;
	struct s_lnode	*prev_node;
	t_list			*data;
}	t_lnode;

typedef struct s_llist
{
	t_lnode	*head;
	t_lnode	*tail;
	int		size;
	double	max;
}	t_llist;

void	init_list(t_list *list);
void	clean_list(t_list *list);
void	push_arg(t_list *list, double z, double x, double y);
int		pop_arg(t_list *list);
t_node	*copy_node(t_node *src);

void	init_llist(t_llist *list);
void	clean_llist(t_llist *list);
void	push_list(t_llist *list);
void	pop_list(t_llist *list);
t_lnode	*erase_list(t_llist *list, t_lnode *target);

#endif