/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:00:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/04 17:07:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# define BUFFER_SIZE 100

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
	int		pipe[2];
	int		input[2];
}	t_fds;

#endif