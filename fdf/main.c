/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/24 17:03:36 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"
#include "./utility/utility.h"
#include "./data_structure/list.h"

#include <stdio.h>
void	temp_parsing(char *file, t_llist *llist)
{
	char	**splited;
	char	*str;
	int 	fd;
	int		i;
	
	fd = open(file, O_RDONLY);
	str = malloc(1);
	while (str != 0)
	{
		free(str);
		str = get_next_line(fd);
		if (str == 0)
			return ;
		push_list(llist);
		splited = ft_split(str, ' ');
		i = 0;
		while (splited[i] != 0)
		{
			push_arg(llist->tail->data, ft_atoi(splited[i]));
			++i;
		}
	}
}

void	temp_print(t_llist *llist)
{
	t_lnode	*lnode;
	t_node	*node;

	lnode = llist->head;
	while (lnode != 0)
	{
		node = lnode->data->head;
		while (node != 0)
		{
			printf("%d\t", node->data);
			node = node->next_node;
		}
		printf("\n");
		lnode = lnode->next_node;
	}
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_llist	llist;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Hello");
	init_llist(&llist);
	temp_parsing(av[1], &llist);
	//temp_print(&llist);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	return (0);
}

// cc -lmlx -framework OpenGL -framework AppKit *.c