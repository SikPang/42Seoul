/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:03:58 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 10:25:53 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>	//free(), NULL
# include "pm_mem.h"	//check_null_after_malloc()

typedef struct s_map
{
	int		**grid;
	int		width;
	int		height;
	int		max_length;
	int		x_max;
	int		y_max;
	char	empty;
	char	obstacle;
	char	full;
}				t_map;

t_map	*new_t_map(void);
void	del_t_map(t_map *this);

#endif
