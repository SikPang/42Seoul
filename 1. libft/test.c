/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:01:05 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/24 21:25:31 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(t_list *lst)
{
	t_list *temp = lst;

	printf("(size : %d) ", ft_lstsize(lst));
	if (!temp)
		printf("--- list is empty ---");
	while (temp)
	{
		printf("%s ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	t_list	*my_list = NULL;

	print_list(my_list);

	ft_lstadd_front(&my_list, ft_lstnew(ft_strdup("111")));
	print_list(my_list);

	ft_lstadd_front(&my_list, ft_lstnew(ft_strdup("222")));
	print_list(my_list);

	ft_lstadd_front(&my_list, ft_lstnew(ft_strdup("333")));
	print_list(my_list);

	ft_lstclear(&my_list, free);
	print_list(my_list);

	ft_lstadd_back(&my_list, ft_lstnew(ft_strdup("111")));
	print_list(my_list);

	ft_lstadd_back(&my_list, ft_lstnew(ft_strdup("222")));
	print_list(my_list);

	ft_lstadd_back(&my_list, ft_lstnew(ft_strdup("333")));
	print_list(my_list);

	ft_lstclear(&my_list, free);
	print_list(my_list);
}