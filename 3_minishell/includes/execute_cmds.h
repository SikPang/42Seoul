/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:06:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/07 15:37:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_CMDS_H
# define EXECUTE_CMDS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "list.h"
# include "enum.h"
# include "parsing_utils.h"
# include "env_var_utils.h"
# include "binary_search_tree.h"
# include "error_handler.h"
# include "libft.h"
# include "builtin_commands.h"
# include "global_var.h"
# include "signal_handler.h"

typedef struct e_fds
{
	int		**pipe;
	int		defaults[2];
	int		pipe_size;
	int		pipe_idx;
	pid_t	last_pid;
}	t_fds;

_Bool	is_include_path(char *str);
char	**get_full_cmd(t_list *cmd_que);
void	close_all_pipes(t_fds *fds);
t_fds	*get_fds(int size);
void	free_2d_char(char **str);
void	wait_all(t_fds *fds);
_Bool	execute(t_tree *envs, t_fds *fds, t_list *cmd_que,
			t_list *parse_que);
void	execute_cmds(t_tree *envs, t_list *parse_que, _Bool	error);
void	p_error(t_list *cmd_que, t_list *parse_que, t_fds *fds);
void	set_default_to_std_fds(t_fds *fds);

#endif
