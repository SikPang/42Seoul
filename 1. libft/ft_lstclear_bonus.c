/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:20:10 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 21:26:36 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*temp;

	cur_node = *lst;
	while (cur_node)
	{
		temp = cur_node->next;
		del(cur_node->content);
		free(cur_node);
		cur_node = temp;
	}
	*lst = (t_list *)0;
}
