/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:25:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/02 16:08:06 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "enum.h"
# include "error_handler.h"
# include "libft.h"

typedef struct s_token
{
	t_token_type	type;
	char			*str;
}	t_token;

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	t_token			data;
}	t_node;

typedef struct s_list
{
	t_node		*head;
	t_node		*tail;
	int			size;
	int			pipe_size;
	t_in_quote	in_quote;
}	t_list;

t_list	*init_list(void);
void	push_back(t_list *list, t_token token);
void	push_front(t_list *list, t_token token);
void	pop_back(t_list *list);
void	pop_front(t_list *list);
_Bool	is_empty(t_list *list);
void	erase_node(t_list *list, t_node *target);
void	destroy_list(t_list **list_ref);
t_token	get_front(t_list *list);

#endif
