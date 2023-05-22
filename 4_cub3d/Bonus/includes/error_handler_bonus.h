/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:32:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/03 11:32:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_BONUS_H
# define ERROR_HANDLER_BONUS_H

# include <stdlib.h>
# include <stdio.h>

typedef enum e_error_mode
{
	error_malloc = 0,
	error_open = 1,
	error_read = 2,
	error_arg = 3,
	error_map_elems = 4
}	t_error_mode;

void	perror_and_exit(t_error_mode e_mode);

#endif