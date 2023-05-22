/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:40:40 by sokwon            #+#    #+#             */
/*   Updated: 2022/12/02 17:13:44 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// t_list
#include <stddef.h>	// NULL

void	ft_lstadd_front(t_list **lst_ref, t_list *new)
{
	if (lst_ref == NULL || new == NULL)
		return ;
	if ((*lst_ref) != NULL)
		new->next = (*lst_ref);
	(*lst_ref) = new;
	return ;
}
