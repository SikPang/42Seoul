/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:25:46 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 21:24:47 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == (0))
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *data = "hello, i'm a data";
//  	t_list *l = ft_lstnew(data);

//  	if (!strcmp(data, l->content))
//  		printf("success\n");
//  	else
// 	 	printf("fail\n");
// }
