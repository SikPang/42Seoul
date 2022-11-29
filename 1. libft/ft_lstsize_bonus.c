/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:05:21 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 21:25:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		size;

	temp = lst;
	size = 0;
	while (temp)
	{
		++size;
		temp = temp->next;
	}
	return (size);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
// 	t_list *l;
// 	int actual;
// 	int expected;

// 	l = ft_lstnew(strdup("1"));
// 	l->next = ft_lstnew(strdup("2"));
// 	l->next->next = ft_lstnew(strdup("3"));
// 	expected = 3;
// 	actual = ft_lstsize(l);
// 	if (actual == expected)
// 		printf("suc");
// 	else
// 		printf("fail");
// }