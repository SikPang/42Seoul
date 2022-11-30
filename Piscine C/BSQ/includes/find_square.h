/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:33:05 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/20 09:18:03 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SQUARE_H
# define FIND_SQUARE_H

# include <unistd.h>
# include <stdlib.h>
# include "map.h"

int		get_min(int num1, int num2, int num3);
int		set_map(t_map *map);
void	find_square(t_map *map);
void	print_map(t_map *map);

#endif
