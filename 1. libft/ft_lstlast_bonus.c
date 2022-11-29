/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:07:12 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 22:10:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp != (t_list *)0 && temp->next)
		temp = temp->next;
	return (temp);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
// 	t_list *l;
// 	t_list *expected;
// 	t_list *actual;

// 	l = ft_lstnew(strdup("1"));
// 	l->next = ft_lstnew(strdup("2"));
// 	l->next->next = ft_lstnew(strdup("3"));
// 	expected = l->next->next;
// 	actual = ft_lstlast(l);
// 	if (actual == expected)
// 		printf("suc");
// 	else
// 		printf("fail");
// }