/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:38:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/03 14:38:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <sys/wait.h>
# include "../readline/readline.h"
# include <signal.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include "enum.h"
# include "global_var.h"

void	set_signal_policy_in_paren(void);
void	set_signal_policy_in_child(void);

#endif
