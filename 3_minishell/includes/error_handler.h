/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:03:10 by sokwon            #+#    #+#             */
/*   Updated: 2023/03/02 17:04:33 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <stdlib.h>

# define ERROR_MALLOC 42
# define ERROR_WRITE  424
# define ERROR_READ   4242
# define ERROR_OPEN   42424
# define ERROR_UNLINK 424242
# define ERROR_PIPE   4242424
# define ERROR_FORK   42424242

void	handle_error_and_exit(int exit_code);

#endif
