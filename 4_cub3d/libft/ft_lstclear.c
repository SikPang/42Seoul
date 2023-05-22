/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:14:25 by sokwon            #+#    #+#             */
/*   Updated: 2022/11/28 18:33:26 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// t_list, ft_lstdelone()
#include <stdlib.h>	// NULL, free()

void	ft_lstclear(t_list **lst_ref, void (*del)(void *))
{
	t_list	*now;
	t_list	*next;

	if (lst_ref == NULL || (*lst_ref) == NULL || del == NULL)
		return ;
	now = (*lst_ref);
	(*lst_ref) = NULL;
	while (now != NULL)
	{
		next = now->next;
		ft_lstdelone(now, del);
		now = next;
	}
	return ;
}
