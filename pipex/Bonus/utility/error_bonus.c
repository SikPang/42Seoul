/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:45:14 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/08 17:27:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "utility_bonus.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	perror_exit(void)
{
	//perror("Error");
	write(2, "pError\n", 7);
	exit(1);
}
