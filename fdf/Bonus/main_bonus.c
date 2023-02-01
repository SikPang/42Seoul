/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/01 15:00:23 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "info_bonus.h"
#include "draw/draw_bonus.h"
#include "get_next_line/get_next_line_bonus.h"
#include "utility/utility_bonus.h"
#include "data_structure/list_bonus.h"

static void	check_valid(t_mlx *mlx)
{
	t_lnode	*lnode;
	int		size;

	lnode = mlx->map->head;
	size = lnode->data->size;
	while (lnode != 0)
	{
		if (size != lnode->data->size)
			error_exit();
		lnode = lnode->next_node;
	}
}

static void	get_args(int fd, t_llist *llist)
{
	char	**splited;
	char	*str;
	int		color;
	int		i;

	str = malloc(1);
	while (str != 0)
	{
		free(str);
		str = get_next_line(fd);
		if (str == 0)
			return ;
		push_list(llist);
		splited = ft_split(str, ' ');
		if (splited == 0)
			error_exit();
		i = -1;
		while (splited[++i] != 0)
		{
			push_arg(llist->tail->data, ft_atoi(splited[i], &color),
				i, (llist->size - 1));
			llist->tail->data->tail->color = color;
		}
		free(splited);
	}
}

void	adjust_scale_and_pos(t_mlx *mlx)
{
	int	col;
	int	row;

	col = mlx->map->head->data->size;
	row = mlx->map->size;
	if (col >= row && col * 2.5 >= mlx->map->max)
		mlx->tile_size = 600 / col;
	else if (row >= col && row * 2.5 >= mlx->map->max)
		mlx->tile_size = 600 / row;
	else
		mlx->tile_size = 600 / mlx->map->max * 2.5;
	mlx->start_x = 500;
	mlx->start_y = 250;
	mlx->euler_z = 45.0;
	mlx->euler_x = 35.3;
}

static void	set_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	init_llist(&mlx->map);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (0);
	set_mlx(&mlx);
	get_args(open(av[1], O_RDONLY), mlx.map);
	adjust_scale_and_pos(&mlx);
	check_valid(&mlx);
	draw_map(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	draw_str(&mlx);
	mlx_hook(mlx.win, X_EVENT_PRESS, 0, press_key, &mlx);
	mlx_hook(mlx.win, X_EVENT_EXIT, 0, button_exit, 0);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	return (0);
}
