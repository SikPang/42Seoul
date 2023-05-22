/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:21:43 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 16:07:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_bonus.h"

void	move(int key, t_info *info)
{
	t_vector2	right_dir;
	t_vector2	move_dir;

	right_dir = rotate_matrix(info->dir, to_radian(90.f));
	move_dir = get_move_dir(key, info, right_dir);
	if (is_collided(key, info, right_dir, move_dir))
		return ;
	info->player.x += move_dir.x * MOVE_SPEED;
	info->player.y += move_dir.y * MOVE_SPEED;
	door_action(info);
}

void	rotate(int key, t_info *info)
{
	float		radian;

	radian = to_radian(ROTATE_DEGREE);
	if (key == KEY_LEFT)
		radian = -radian;
	info->dir = rotate_matrix(info->dir, radian);
	info->plane = rotate_matrix(info->plane, radian);
}

int	mouse_move(int x, int y, t_info *info)
{
	(void)y;
	if (x < WIN_WIDTH / 2)
		rotate(KEY_LEFT, info);
	else
		rotate(KEY_RIGHT, info);
	mlx_mouse_move(info->canvas->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

int	press_key(int key, t_info *info)
{
	if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate(key, info);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(key, info);
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	exit_on_event(void)
{
	exit(0);
	return (1);
}
