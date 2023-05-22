/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:27:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 17:24:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_code_mac_bonus.h"
#include "mlx.h"
#include "error_handler_bonus.h"
#include "parsing_bonus.h"
#include "draw_bonus.h"
#include "event_bonus.h"
#include "frame_bonus.h"

void	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4 || str[len - 4] != '.' || str[len - 3] != 'c'
		|| str[len - 2] != 'u' || str[len - 1] != 'b')
		perror_and_exit(error_open);
}

int	main(int argc, char **argv)
{
	t_info	*map_info;

	if (argc != 2)
		perror_and_exit(error_arg);
	check_extension(argv[1]);
	map_info = parse_map_data(argv[1]);
	map_info->canvas = init_canvas(WIN_WIDTH, WIN_HEIGHT);
	check_texture(map_info);
	check_sprite(map_info);
	init_vectors(map_info);
	door_action(map_info);
	mlx_hook(map_info->canvas->win, EVENT_KEY_PRESS, 0, press_key, map_info);
	mlx_hook(map_info->canvas->win, EVENT_WINDOW_CLOSE, 0, exit_on_event, NULL);
	mlx_hook(map_info->canvas->win, EVENT_MOUSE_MOVE, 0, mouse_move, map_info);
	mlx_loop_hook(map_info->canvas->mlx, frame, map_info);
	mlx_mouse_hide();
	mlx_loop(map_info->canvas->mlx);
	destroy_canvas(&map_info->canvas);
	destroy_info(map_info);
	return (0);
}
