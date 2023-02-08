/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:00:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/08 14:24:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_BONUS_H
# define INFO_BONUS_H

# define READ 0
# define WRITE 1

# define STD_IN 0
# define STD_OUT 1

typedef struct s_args
{
	int		ac;
	char	**av;
	char	**ev;
	char	**paths;
}	t_args;

typedef struct s_fds
{
	int		**pipe;
	int		pipe_size;
	int		input[2];
}	t_fds;

typedef struct s_here_doc
{
	int		pipe[2];
	int		outfile;
}	t_here_doc;

void	here_doc(t_args	*arg);
void	dup_fds(t_fds *fd, t_args *arg, int count);
void	close_fds(t_fds *fd, t_args *arg, int count);

#endif