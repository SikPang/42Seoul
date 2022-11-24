/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:28:47 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/24 21:43:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cur_node;
	t_list	*temp_node;
	void	*temp_content;

	new_lst = (t_list *)0;
	cur_node = lst;
	while (cur_node)
	{
		temp_content = f(cur_node->content);
		temp_node = ft_lstnew(temp_content);
		if (temp_node == (t_list *)0)
		{
			free(temp_content);
			ft_lstclear(&new_lst, del);
			return ((t_list *)0);
		}
		ft_lstadd_back(&new_lst, temp_node);
		cur_node = cur_node->next;
	}
	return (new_lst);
}
