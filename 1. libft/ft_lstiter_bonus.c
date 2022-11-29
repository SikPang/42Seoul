/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:26:38 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 22:28:01 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// void			lstiter_f(void *content) {
// 	char *s = content;

// 	s[0] = 'O';
// 	s[1] = 'K';
// }

// int main()
// {
// 	t_list *l = ft_lstnew(strdup("KO !"));

// 	l->next = ft_lstnew(strdup("KO !"));
// 	l->next->next = ft_lstnew(strdup("KO !"));
// 	ft_lstiter(l, lstiter_f);
// 	if (!strcmp(l->content, "OK !") && !strcmp(l->next->content, "OK !") 
//		&& !strcmp(l->next->next->content, "OK !"))
// 		printf("suc");
// 	else
// 		printf("fail");
// }