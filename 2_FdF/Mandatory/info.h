/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:56:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/01 16:11:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "data_structure/list.h"

# define X_EVENT_PRESS 2
# define X_EVENT_EXIT 17
# define KEY_ESC 53

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct s_mlx
{
	t_llist	*map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		tile_size;
	int		start_x;
	int		start_y;
	double	euler_z;
	double	euler_x;
}	t_mlx;

int		press_key(int key);
int		button_exit(void);

#endif