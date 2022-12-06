/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:34:44 by song              #+#    #+#             */
/*   Updated: 2022/12/06 21:12:44 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static t_list	list;
	t_node_			*target;
	
	target = find_node(&list, fd, 1);
	if (!target)
		return (0);
	while (1)
	{
		
	}
}
