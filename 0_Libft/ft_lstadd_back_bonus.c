/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:12:06 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 22:12:31 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp == (t_list *)0)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
// 	t_list *l0 = ft_lstnew(strdup("nyacat"));
// 	t_list *n0 = ft_lstnew(strdup("OK"));

// 	ft_lstadd_back(&l0, n0);
// 	if (l0->next == n0 && !strcmp(l0->next->content, "OK"))
// 	{
// 		printf("suc\n");
// 	}
// 	else
// 		printf("fail\n");

// 	t_list *l = ft_lstnew(strdup("nyacat"));
// 	t_list *n = ft_lstnew(strdup("OK"));

// 	ft_lstadd_back(&l, n);
// 	if (l->next == n && !strcmp(l->next->content, "OK"))
// 	{
// 		free(l->next);
// 		free(l);
// 		printf("suc\n");
// 	}
// 	else
// 	{
// 		free(l->next);
// 		free(l);
// 		printf("fail\n");
// 	}
// }