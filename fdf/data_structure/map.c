/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:29:00 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 20:36:19 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>

void	init_map(t_map *map, char *file)
{
	int 	fd;
	
	fd = open(file, O_RDONLY);
	map->height = count_height(map, fd);
	map->width = 
	close(fd);
}
