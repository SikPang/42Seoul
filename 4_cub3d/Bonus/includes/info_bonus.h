/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:10:39 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 17:24:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_BONUS_H
# define INFO_BONUS_H

# include <stdlib.h>
# include "canvas_bonus.h"
# include "libft.h"
# include "ft_math_bonus.h"
# include "list_bonus.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define FOV 0.66

# define NORTH 0
# define SOUTH 1
# define WEST  2
# define EAST  3

# define ANIMATION_SIZE 12
# define SPRITE_PATH_1 "./Resources/zombie1.xpm"
# define SPRITE_PATH_2 "./Resources/zombie2.xpm"
# define SPRITE_PATH_3 "./Resources/zombie3.xpm"
# define SPRITE_PATH_4 "./Resources/zombie4.xpm"
# define SPRITE_PATH_5 "./Resources/zombie5.xpm"
# define SPRITE_PATH_6 "./Resources/zombie6.xpm"
# define SPRITE_PATH_7 "./Resources/zombie7.xpm"
# define SPRITE_PATH_8 "./Resources/zombie8.xpm"
# define SPRITE_PATH_9 "./Resources/zombie9.xpm"
# define SPRITE_PATH_10 "./Resources/zombie10.xpm"
# define SPRITE_PATH_11 "./Resources/zombie11.xpm"
# define SPRITE_PATH_12 "./Resources/zombie12.xpm"

# define WALL_TEXTURE_SIZE 4
# define DOOR_TEXTURE_SIZE 3

# define SPRITE     '3'
# define DOOR_OPENED 4
# define DOOR_CLOSED 5
# define DOOR_SIDE   6

# define DOOR_OPENED_PATH "./Resources/door_opened.xpm"
# define DOOR_CLOSED_PATH "./Resources/door_closed.xpm"
# define DOOR_SIDE_PATH "./Resources/door_side.xpm"

typedef struct s_texture
{
	void	*img;
	int		width;
	int		height;
	char	*path;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_sprite
{
	t_texture	source[ANIMATION_SIZE];
	t_texture	*cur;
	int			count;
}	t_sprite;

typedef struct s_info
{
	t_texture	textures[WALL_TEXTURE_SIZE + DOOR_TEXTURE_SIZE];
	t_sprite	sprite;
	int			f_color;
	int			c_color;
	int			width;
	int			height;
	char		**map;
	int			frame_count;
	t_vector2	player;
	t_vector2	dir;
	t_vector2	plane;
	t_canvas	*canvas;
	float		z_buffer[WIN_WIDTH];
	t_list		*door_list;
	t_list		*sprite_list;
}	t_info;

t_info	*init_info(void);
void	destroy_info(t_info *info);

#endif