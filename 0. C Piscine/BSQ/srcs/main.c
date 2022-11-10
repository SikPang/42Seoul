/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:28:30 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/20 12:09:59 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "pm_mem.h"
#include "pm_stdin.h"
#include "pm_file.h"
#include "map.h"
#include "map_parser.h"
#include "split.h"
#include "find_square.h"

char	*pm_read_stdin(void)
{
	t_stdin	*si;
	char	*str;

	si = new_t_stdin();
	str = si->gets(si);
	if (str == NULL || *str == '\0')
		str = NULL;
	del_t_stdin(si);
	return (str);
}

void	start_bsq(int ac, char *av[])
{
	t_map	*map;
	int		i;

	i = 0;
	if (ac == 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	while (i < ac)
	{
		map = parsing_map(av[i]);
		if (map == NULL)
			write(1, "map error\n", 10);
		else
		{
			find_square(map);
			print_map(map);
		}
		if (i + 1 < ac)
			write(1, "\n", 1);
		++i;
	}
}

int	main(int ac, char *av[])
{
	int		length;
	char	**strs;

	length = 0;
	if (ac == 1)
	{
		strs = split(pm_read_stdin(), &length);
		start_bsq(length, strs);
	}
	else
	{
		start_bsq(ac - 1, av + 1);
	}
}
