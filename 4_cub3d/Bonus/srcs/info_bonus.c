/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:29:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 19:58:33 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

t_info	*init_info(void)
{
	t_info	*new;

	new = (t_info *)ft_calloc(1, sizeof(t_info));
	if (new == NULL)
		perror_and_exit(error_malloc);
	new->door_list = init_list();
	new->sprite_list = init_list();
	return (new);
}

void	destroy_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < WALL_TEXTURE_SIZE + DOOR_TEXTURE_SIZE)
	{
		mlx_destroy_image(info->canvas->mlx, info->textures[i].img);
		if (i < WALL_TEXTURE_SIZE)
			free(info->textures[i].path);
	}
	i = -1;
	while (++i < ANIMATION_SIZE)
		mlx_destroy_image(info->canvas->mlx, info->sprite.source[i].img);
	i = -1;
	while (++i < info->height)
	{
		free(info->map[i]);
	}
	destroy_list(&info->door_list);
	destroy_list(&info->sprite_list);
	free(info->map);
	free(info);
}
