/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:28:47 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 22:28:46 by kwsong           ###   ########.fr       */
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

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// void *		lstmap_f(void *content) {

// 	(void)content;
// 	return ("OK !");
// }

// void			lstdel_f(void *lst) {
// 	(void)lst;
// }

// int main()
// {
// 	t_list *l = ft_lstnew(strdup(" 1 2 3 "));
// 	t_list *ret;

// 	l->next = ft_lstnew(strdup("ss"));
// 	l->next->next = ft_lstnew(strdup("-_-"));
// 	ret = ft_lstmap(l, lstmap_f, lstdel_f);
// 	if (!strcmp(ret->content, "OK !") 
//		&& !strcmp(ret->next->content, "OK !") 
//		&& !strcmp(ret->next->next->content, "OK !") 
//		&& !strcmp(l->content, " 1 2 3 ") 
//		&& !strcmp(l->next->content, "ss") 
//		&& !strcmp(l->next->next->content, "-_-"))
// 		printf("suc\n");
// 	else
// 		printf("fail\n");
// }