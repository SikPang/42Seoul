/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:25:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 17:24:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_BONUS_H
# define LIST_BONUS_H

# include "error_handler_bonus.h"
# include "libft.h"
# include "ft_math_bonus.h"

typedef union u_data
{
	t_vector2	vec;
	char		*str;
}	t_data;

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	t_data			data;
}	t_node;

typedef struct s_list
{
	t_node		*head;
	t_node		*tail;
	int			size;
}	t_list;

t_list	*init_list(void);
void	push_back(t_list *list, t_data data);
void	push_front(t_list *list, t_data data);
void	pop_back(t_list *list);
void	pop_front(t_list *list);
_Bool	is_empty(t_list *list);
void	erase_node(t_list *list, t_node *target);
void	destroy_list(t_list **list_ref);
t_data	get_front(t_list *list);

#endif
