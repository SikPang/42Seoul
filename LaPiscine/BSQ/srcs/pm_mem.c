/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:30:07 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 11:25:30 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pm_mem.h"

int	occur_error(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	return (0);
}

void	check_null_after_malloc(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr("malloc failure!\n");
		exit(1);
	}
	return ;
}

void	pm_memcpy(void *dest, void *src, unsigned int n)
{
	char	*csrc;
	char	*cdest;

	csrc = (char *)src;
	cdest = (char *)dest;
	while (n > 0)
	{
		*(cdest++) = *(csrc++);
		n--;
	}
}

void	*pm_realloc(void *ptr,
			unsigned int original_length, unsigned int new_length)
{
	void	*new_ptr;

	if (new_length == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		return (malloc(new_length));
	}
	else if (new_length <= original_length)
	{
		return (ptr);
	}
	else
	{
		new_ptr = malloc(new_length);
		if (new_ptr != NULL)
		{
			pm_memcpy(new_ptr, ptr, original_length);
			free(ptr);
		}
		return (new_ptr);
	}
}
