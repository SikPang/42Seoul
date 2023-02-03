/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/03 15:50:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility/utility.h"

#include <stdio.h>
static char	**get_paths(char **ev)
{
	char	**paths;

	paths = 0;
	while (*ev != 0)
	{
		if (ft_strncmp(*ev, "PATH=", 5) == 0)
		{
			paths = ft_split((*ev) + 5, ':');
			break ;
		}
		++ev;
	}
	return (paths);
}

int main(int ac, char **av, char **ev)
{
	char	**paths;

	paths = get_paths(ev);
	
}