/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:10:37 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 17:24:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "info_bonus.h"
# include "libft.h"
# include "error_handler_bonus.h"
# include "get_next_line_bonus.h"
# include "list_bonus.h"
# include "stack_bonus.h"
# include "ft_math_bonus.h"

# define NUM_OF_ELEMS 6

void	binding_sprite_path(t_info *info);
_Bool	is_door_surrounded(t_info *info, t_vector2 cur);
void	check_valid(t_info *new, char c, t_vector2 pos);
int		get_color(char *color_data);
_Bool	is_color_string(char *arg);
void	free_split(char **strs);
t_info	*parse_map_data(char *map_data_path);
void	check_surrounded(t_info *info);
void	check_sprite(t_info *new);
void	check_texture(t_info *new);
void	check_side(t_info *new);
int		count_num_of_commas(char *str);

#endif