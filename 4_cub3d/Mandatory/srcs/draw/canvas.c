/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:04:56 by sokwon            #+#    #+#             */
/*   Updated: 2023/05/04 13:47:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	*init_canvas(int width, int height)
{
	t_canvas	*new;

	new = (t_canvas *)malloc(sizeof(t_canvas));
	if (new == NULL)
		perror_and_exit(error_malloc);
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, width, height, "cub3D");
	new->width = width;
	new->height = height;
	new->img.image = mlx_new_image(new->mlx, width, height);
	new->img.data = (int *)mlx_get_data_addr(new->img.image,
			&new->img.bits_per_pixel, &new->img.size_line, &new->img.endian);
	new->draw_pixel = t_canvas_draw_pixel;
	new->show = t_canvas_show;
	return (new);
}

void	t_canvas_draw_pixel(t_canvas *this, int w, int h, int color)
{
	this->img.data[this->width * h + w] = color;
}

void	t_canvas_show(t_canvas *this)
{
	mlx_put_image_to_window(this->mlx, this->win, this->img.image, 0, 0);
}

void	destroy_canvas(t_canvas **this_ref)
{
	t_canvas	*this;

	this = *this_ref;
	mlx_destroy_image(this->mlx, this->img.image);
	free(this);
	*this_ref = NULL;
}
