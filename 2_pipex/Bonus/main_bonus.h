/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:34:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/09 20:03:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# define _NULL 0

# define READ 0
# define WRITE 1

# define STD_IN 0
# define STD_OUT 1

typedef struct s_arg
{
	int		ac;
	char	**av;
	char	**ev;
	char	**paths;
}	t_arg;

typedef struct s_fd
{
	int		prev_pipe[2];
	int		cur_pipe[2];
	int		file[2];
}	t_fd;

void	wait_all(int size);
char	**get_paths(char **ev);
void	close_fds(t_fd *fd, int i, int last);
void	dup_fds(t_fd *fd, int i, int last);
void	child_process(t_arg *arg, t_fd *fd, int count, int cmd_size);
void	pipex(t_arg *arg, t_fd *fd, int i, int cmd_size);
void	here_doc(t_arg *arg, t_fd *fd);

#endif