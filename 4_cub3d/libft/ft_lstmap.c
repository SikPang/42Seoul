/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:31:48 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 17:30:44 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// t_list, ft_lstnew, ft_lstclear(), ft_lstadd_front()
#include <stdlib.h>	// NULL, malloc(), free()

static void	ft_noop_del(void *content)
{
	(void)content;
	return ;
}

static t_list	*ft_lst_getlst(int size)
{
	t_list	*lst;
	t_list	*new;

	lst = (t_list *) NULL;
	while (size-- > 0)
	{
		new = ft_lstnew(NULL);
		if (new == NULL)
		{
			ft_lstclear(&lst, ft_noop_del);
			break ;
		}
		ft_lstadd_front(&lst, new);
	}
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*mapped_lst;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	mapped_lst = ft_lst_getlst(ft_lstsize(lst));
	if (mapped_lst == NULL)
		return (NULL);
	result = mapped_lst;
	while (lst != NULL)
	{
		mapped_lst->content = f(lst->content);
		lst = lst->next;
		mapped_lst = mapped_lst->next;
	}
	return (result);
}
