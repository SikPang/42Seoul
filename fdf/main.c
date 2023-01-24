/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 16:02:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"
#include "./utility/utility.h"
#include "./data_structure/list.h"

static void	mini_parsing(char *file, t_list *list)
{
	char	**splited;
	char	*str;
	int 	fd;
	int		i;
	
	fd = open(file, O_RDONLY);
	while (str != 0)
	{
		str = get_next_line(fd);
		if (str == 0)
			return ;
		splited = ft_split(str, ' ');
		i = 0;
		while (splited[i] != 0)
		{
			push_back(&list, ft_atoi(splited[i]));
			++i;
		}
	}
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_list	list;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Hello");
	mini_parsing(av[1], &list);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	return (0);
}

// cc -lmlx -framework OpenGL -framework AppKit *.c