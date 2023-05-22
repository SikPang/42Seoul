/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:18:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/01 16:55:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include "error_handler_bonus.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnode
{
	struct s_gnode	*next_node;
	struct s_gnode	*prev_node;
	char			*data;
	int				fd;
}	t_gnode;

typedef struct s_glist
{
	t_gnode	*head;
	t_gnode	*tail;
}	t_glist;

t_gnode	*gpush_back(t_glist *list, int fd);
t_gnode	*gfind_node(t_glist *list, int fd);
void	gdelete_node(t_glist *list, t_gnode *target);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strnjoin(char *s1, char *s2, ssize_t byte);
char	*get_last(t_glist *list, t_gnode *target, ssize_t byte);
char	*get_result(t_glist *list, t_gnode *target, size_t result_len,
			size_t data_len);
size_t	ft_strchri(char *s, char c);
ssize_t	read_buf(t_gnode *target, int fd);
char	*get_next_line(int fd);

#endif
