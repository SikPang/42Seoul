/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:56:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/01 16:08:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_BONUS_H
# define INFO_BONUS_H

# include "data_structure/list_bonus.h"

# define X_EVENT_PRESS 2
# define X_EVENT_EXIT 17
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20

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

void	adjust_scale_and_pos(t_mlx *mlx);
void	set_default(t_mlx *mlx);
void	update_window(t_mlx *mlx);
void	to_orthogonal_z(t_mlx *mlx);
void	to_orthogonal_y(t_mlx *mlx);
int		press_key(int key, t_mlx *mlx);
int		button_exit(void);

#endif