/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:27:01 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/01 19:28:05 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

void	perror_and_exit(t_error_mode e_mode)
{
	static char	*error_msgs[] = {"Malloc error", "Can't open file",
		"Read error", "Arg error", "Invalid map data"};

	printf("Error\n");
	printf("%s\n", error_msgs[e_mode]);
	exit(e_mode);
}
