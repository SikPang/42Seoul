/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:22 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 21:22:45 by kwsong           ###   ########.fr       */
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
// 	t_list *l = ft_lstnew(strdup("nyacat"));
// 	t_list *n = ft_lstnew(strdup("OK"));

// 	ft_lstadd_front(&l, n);
// 	if (l == n && !strcmp(l->content, "OK"))
// 	{
// 		free(l->next);
// 		free(l);
// 		printf("suc");
// 	}
// 	else
// 	{
// 		free(l->next);
// 		free(l);
// 		printf("fail");	
// 	}
// }