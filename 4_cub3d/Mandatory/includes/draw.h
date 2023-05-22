/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:46:57 by sokwon            #+#    #+#             */
/*   Updated: 2023/05/09 13:10:21 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "info.h"
# include "canvas.h"
# include "error_handler.h"
# include "raycasting.h"
# include "minimap.h"
# include "ft_math.h"
# include "sprite.h"

# define BUFFER_OVERFLOW 0xFF000000

typedef struct s_draw
{
	t_vector2	texture_pos;
	float		texture_step;
	int			line_height;
	int			line_start;
	int			line_end;
	int			pos;
}	t_draw;

int		get_texture_num(t_dda_info *dda);
int		get_pixel(t_texture *texture, int x, int y);
int		get_tex_x(t_info *info, t_dda_info *dda, t_texture *texture);
void	init_vectors(t_info *info);
void	draw(t_info *info);

#endif
