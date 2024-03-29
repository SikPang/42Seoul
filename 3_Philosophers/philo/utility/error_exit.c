/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:45:14 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/12 11:46:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utility.h"

void	error_exit(t_error code)
{
	if (code == ARG)
		write(2, "Arguments ", 11);
	else if (code == MALLOC)
		write(2, "Malloc ", 8);
	write(2, "Error\n", 6);
	exit(ERROR);
}
