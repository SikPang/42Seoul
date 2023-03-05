/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:22 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 22:09:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
// 	t_list *l0 = ft_lstnew(strdup("nyacat"));
// 	t_list *n0 = ft_lstnew(strdup("OK"));

// 	ft_lstadd_front(&l0, n0);
// 	if (l0 == n0 && !strcmp(l0->content, "OK"))
// 	{
// 		printf("suc\n");
// 	}
// 	else
// 		printf("fail\n");

// 	t_list *l = ft_lstnew(strdup("nyacat"));
// 	t_list *n = ft_lstnew(strdup("OK"));

// 	ft_lstadd_front(&l, n);
// 	if (l == n && !strcmp(l->content, "OK"))
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

// 	t_list *l2 = ((void *)0);
// 	t_list *n2 = ft_lstnew(strdup("OK"));

// 	ft_lstadd_front(&l2, n2);
// 	if (l2 == n2 && !strcmp(l2->content, "OK"))
// 	{
// 		free(l2->next);
// 		free(l2);
// 		printf("suc\n");
// 	}
// 	else
// 	{
// 		free(l2->next);
// 		free(l2);
// 		printf("fail\n");
// 	}	
// }