/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:56:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/26 22:04:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# define TILE_SIZE 30
# define START_POS 300

# define X_EVENT_PRESS 2
# define X_EVENT_EXIT 17
# define KEY_ESC 53

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

int	press_key(int key_code);
int	key_exit(int key_code);

#endif