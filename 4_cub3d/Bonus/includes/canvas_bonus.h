/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:46:57 by sokwon            #+#    #+#             */
/*   Updated: 2023/05/15 17:24:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_BONUS_H
# define CANVAS_BONUS_H

# include <stdlib.h>
# include "mlx.h"
# include "error_handler_bonus.h"

typedef struct s_image_info
{
	void	*image;
	int		*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image_info;

typedef struct s_canvas	t_canvas;
struct s_canvas
{
	void			(*draw_pixel)(t_canvas *this, int w, int h, int color);
	void			(*show)(t_canvas *this);

	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_image_info	img;
};

t_canvas	*init_canvas(int width, int height);
void		t_canvas_draw_pixel(t_canvas *this, int w, int h, int color);
void		t_canvas_show(t_canvas *this);
void		destroy_canvas(t_canvas **this);

#endif
