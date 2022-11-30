/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:16:29 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 22:27:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// void			lstdelone_f(void *d) {
// 	free(d);
// }

// int main()
// {
// 	t_list *l = ft_lstnew(strdup("nyancat"));

// 	l->next = ft_lstnew(strdup("#TEST#"));
// 	ft_lstclear(&l, lstdelone_f);
// 	if (!l)
// 		printf("suc\n");
// 	else
// 		printf("fail\n");
// }