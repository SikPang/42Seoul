/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:21:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/08 15:32:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "info.h"
# include "ft_math.h"

# define MINIMAP_START_POS 25
# define MINIMAP_SIZE 250
# define BORDER_SIZE 5
# define CUB_SIZE 8
# define CENTER 14

# define COLOR_BLACK  0x00000000
# define COLOR_GRAY   0x00555555
# define COLOR_WHITE  0x00FFFFFF
# define COLOR_YELLOW 0x00FFFF00
# define COLOR_RED    0x00FF0000
# define COLOR_GREEN  0x00009900
# define COLOR_BLUE   0x003333FF

void	render_minimap(t_info *info);

#endif