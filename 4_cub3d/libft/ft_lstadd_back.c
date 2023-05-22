/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:02:31 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 16:33:54 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// t_list, ft_lstlast()
#include <stddef.h>	// NULL

void	ft_lstadd_back(t_list **lst_ref, t_list *new)
{
	t_list	*back;

	if (lst_ref == NULL)
		return ;
	if ((*lst_ref) == NULL)
	{
		(*lst_ref) = new;
		return ;
	}
	back = ft_lstlast(*lst_ref);
	back->next = new;
	return ;
}
