/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:50:02 by sokwon            #+#    #+#             */
/*   Updated: 2022/11/28 16:58:33 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// t_list
#include <stddef.h>	// NULL

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
