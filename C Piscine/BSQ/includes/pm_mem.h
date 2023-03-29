/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:29:32 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 11:04:08 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_MEM_H
# define PM_MEM_H

# include <stdlib.h>	//malloc(), free(), exit(), NULL
# include "ft_putstr.h"

int		occur_error(void *ptr);
// exit(1) (malloc fail)
void	check_null_after_malloc(void *ptr);
void	pm_memcpy(void *dest, void *src, unsigned int n);
void	*pm_realloc(void *ptr,
			unsigned int original_length, unsigned int new_length);

#endif
