/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:48:14 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/15 15:58:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	interpret_line(t_info *new, char **strs)
{
	int				i;
	static char		*id[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	static _Bool	is_setup[] = {0, 0, 0, 0, 0, 0};
	const void		*elems[] = {&(new->textures[NORTH].path),
		&(new->textures[SOUTH].path), &(new->textures[WEST].path),
		&(new->textures[EAST].path), &(new->f_color), &(new->c_color)};

	i = -1;
	while (id[++i] != NULL)
	{
		if (ft_strncmp(strs[0], id[i], -(size_t)1) != 0)
			continue ;
		if (is_setup[i])
			perror_and_exit(error_map_elems);
		if (i < WALL_TEXTURE_SIZE)
			*(char **)elems[i] = ft_strdup(strs[1]);
		else
			*(int *)elems[i] = get_color(strs[1]);
		is_setup[i] = 1;
		return ;
	}
	perror_and_exit(error_map_elems);
}

static void	read_elems(t_info *new, int fd)
{
	char	*line;
	char	**strs;
	int		num_of_chunk;
	int		i;

	i = 0;
	while (i < NUM_OF_ELEMS)
	{
		line = get_next_line(fd);
		if (line == NULL)
			perror_and_exit(error_map_elems);
		strs = ft_split(line, ' ');
		num_of_chunk = 0;
		while (strs[num_of_chunk] != NULL)
			num_of_chunk++;
		if (num_of_chunk == 2)
		{
			interpret_line(new, strs);
			i++;
		}
		else if (num_of_chunk != 0)
			perror_and_exit(error_map_elems);
		free(line);
		free_split(strs);
	}
}

static void	set_map(t_info *new, t_list *line_list)
{
	int		h;
	int		w;

	new->map = (char **)ft_calloc(new->height, sizeof(char *));
	if (new->map == NULL)
		perror_and_exit(error_malloc);
	h = 0;
	while (h < new->height)
	{
		new->map[h] = (char *)malloc(new->width);
		if (new->map[h] == NULL)
			perror_and_exit(error_malloc);
		ft_memset(new->map[h], ' ', new->width);
		w = 0;
		while (get_front(line_list).str[w] != '\n'
			&& get_front(line_list).str[w] != '\0')
		{
			check_valid(new, get_front(line_list).str[w], (t_vector2){w, h});
			new->map[h][w] = get_front(line_list).str[w];
			++w;
		}
		pop_front(line_list);
		++h;
	}
}

static void	read_map(t_info *new, int fd)
{
	t_list	*line_list;
	char	*line;
	int		width;

	line_list = init_list();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line == '\n' && new->width == 0)
		{
			free(line);
			continue ;
		}
		width = ft_strlen(line) - 1;
		if (width > new->width)
			new->width = width;
		push_back(line_list, (t_data){.str = line});
	}
	new->height = line_list->size;
	if (new->height < 3 || new->width < 3)
		perror_and_exit(error_map_elems);
	set_map(new, line_list);
	destroy_list(&line_list);
}

t_info	*parse_map_data(char *map_data_path)
{
	t_info	*new;
	t_node	*cur;
	int		fd;

	fd = open(map_data_path, O_RDONLY);
	if (fd == -1)
		perror_and_exit(error_open);
	new = init_info();
	read_elems(new, fd);
	read_map(new, fd);
	if (new->player.x == 0.f && new->player.y == 0.f)
		perror_and_exit(error_map_elems);
	close(fd);
	check_side(new);
	cur = new->door_list->head;
	while (cur != NULL)
	{
		if (!is_door_surrounded(new, cur->data.vec))
			perror_and_exit(error_map_elems);
		cur = cur->next;
	}
	check_surrounded(new);
	return (new);
}
