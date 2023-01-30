/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 18:51:48 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "info.h"
#include "draw/draw.h"
#include "get_next_line/get_next_line.h"
#include "utility/utility.h"
#include "data_structure/list.h"

#include <stdio.h>
static void	temp_print(t_llist *llist)
{
	t_lnode	*lnode;
	t_node	*node;

	lnode = llist->head;
	while (lnode != 0)
	{
		node = lnode->data->head;
		while (node != 0)
		{
			//printf("%.0f %.0f %.0f\t", node->y, node->x, node->z);
			printf("%.0f\t", node->z);
			//printf("%d\t", node->color);
			node = node->next_node;
		}
		lnode = lnode->next_node;
	}
}

static void	check_valid(t_llist *llist)
{
	t_lnode	*lnode;
	int		size;

	lnode = llist->head;
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
		i = 0;
		while (splited[i] != 0)
		{
			push_arg(llist->tail->data, ft_atoi(splited[i], &color)
				* (TILE * 0.15), i * TILE, (llist->size - 1) * TILE);
			llist->tail->data->tail->color = color;
			++i;
		}
	}
}

static void	set_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
					&mlx->size_line, &mlx->endian);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_llist	map;

	if (ac != 2)
		return (0);
	set_mlx(&mlx);
	init_llist(&map);
	get_args(open(av[1], O_RDONLY), &map);
	check_valid(&map);
	//temp_print(&map);
	draw_map(&map, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, X_EVENT_PRESS, 0, press_key, 0);
	mlx_hook(mlx.win, X_EVENT_EXIT, 0, button_exit, 0);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	return (0);
}
