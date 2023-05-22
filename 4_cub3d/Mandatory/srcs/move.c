/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:51:47 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/09 13:28:44 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

static t_vector2	get_player_side(int key, t_info *info,
	t_vector2 right_dir, int side)
{
	if (key == KEY_W)
		return ((t_vector2){info->player.x + FAT * side * right_dir.x,
			info->player.y + FAT * side * right_dir.y});
	else if (key == KEY_S)
		return ((t_vector2){info->player.x - FAT * side * right_dir.x,
			info->player.y - FAT * side * right_dir.y});
	else if (key == KEY_A)
		return ((t_vector2){info->player.x + FAT * side * info->dir.x,
			info->player.y + FAT * side * info->dir.y});
	else
		return ((t_vector2){info->player.x - FAT * side * info->dir.x,
			info->player.y - FAT * side * info->dir.y});
}

_Bool	is_collided(int key, t_info *info, t_vector2 right_dir
	, t_vector2 move_dir)
{
	t_vector2	temp_pos;
	t_dda_info	*left;
	t_dda_info	*right;

	left = NULL;
	right = NULL;
	temp_pos = info->player;
	info->player = get_player_side(key, info, right_dir, LEFT);
	left = raycasting(info, move_dir);
	info->player = temp_pos;
	info->player = get_player_side(key, info, right_dir, RIGHT);
	right = raycasting(info, move_dir);
	info->player = temp_pos;
	if ((left->hit_x && left->cur_dist.y <= MOVE_SPEED + FAT)
		|| (!left->hit_x && left->cur_dist.x <= MOVE_SPEED + FAT)
		|| (right->hit_x && right->cur_dist.y <= MOVE_SPEED + FAT)
		|| (!right->hit_x && right->cur_dist.x <= MOVE_SPEED + FAT))
	{
		free(left);
		free(right);
		return (TRUE);
	}
	free(left);
	free(right);
	return (FALSE);
}

t_vector2	get_move_dir(int key, t_info *info, t_vector2 right_dir)
{
	t_vector2	move_dir;

	if (key == KEY_W)
		move_dir = (t_vector2){info->dir.x, info->dir.y};
	else if (key == KEY_S)
		move_dir = (t_vector2){-info->dir.x, -info->dir.y};
	else if (key == KEY_A)
		move_dir = (t_vector2){-right_dir.x, -right_dir.y};
	else
		move_dir = (t_vector2){right_dir.x, right_dir.y};
	return (move_dir);
}

void	door_action(t_info *info)
{
	t_node	*cur;

	cur = info->door_list->head;
	while (cur != NULL)
	{
		if (get_distance(info->player, cur->data.vec)
			< powf(DIST_DOOR_ACTION, 2))
		{
			if (info->map[(int)cur->data.vec.y][(int)cur->data.vec.x]
				== DOOR_CLOSED + '0')
				info->map[(int)cur->data.vec.y][(int)cur->data.vec.x]
					= DOOR_OPENED + '0';
		}
		else
		{
			if (info->map[(int)cur->data.vec.y][(int)cur->data.vec.x]
				== DOOR_OPENED + '0')
				info->map[(int)cur->data.vec.y][(int)cur->data.vec.x]
					= DOOR_CLOSED + '0';
		}
		cur = cur->next;
	}
}
