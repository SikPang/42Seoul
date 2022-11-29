/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:25:46 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 22:20:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == (t_list *)0)
		return ((t_list *)0);
	new->content = content;
	new->next = (t_list *)0;
	return (new);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *data = "hello, i'm a data";
// 	t_list *l = ft_lstnew(data);

// 	if (!strcmp(data, l->content))
// 		printf("success\n");
//  	else
// 	 	printf("fail\n");

// 	char *data2 = "hello, i'm a data";
//  	t_list *l2 = ft_lstnew(data2);

//  	if (!strcmp(data2, l2->content))
//  		printf("success\n");
//  	else
// 	 	printf("fail\n");
// }
