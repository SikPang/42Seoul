/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:56:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 21:45:11 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# define X_EVENT_PRESS 2
# define X_EVENT_EXIT 17
# define KEY_ESC 53
# define KEY_C 8
# define KEY_Z 6
# define KEY_T 17
# define KEY_R 15
# define KEY_I 34

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		tile_size;
	int		start_pos;
}	t_mlx;

int	press_key(int key_code);
int	button_exit(int key_code);

#endif