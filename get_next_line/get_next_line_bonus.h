/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:18:45 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/08 13:18:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_node
{
	struct s_node	*next_node;
	struct s_node	*prev_node;
	char			*data;
	int				fd;
}	t_node_;

typedef struct s_list
{
	t_node_	*head;
	t_node_	*tail;
}	t_list;

t_node_	*push_back(t_list *list, int fd);
t_node_	*find_node(t_list *list, int fd, int check);
void	delete_node(t_list *list, t_node_ *target);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, ssize_t byte);
char	*get_last(t_list *list, t_node_ *target, ssize_t byte);
char	*get_result(t_list *list, t_node_ *target, size_t result_len,
			size_t data_len);
size_t	ft_strchr(char *s, char c);
ssize_t	read_buf(t_node_ *target, int fd);
char	*get_next_line(int fd);

#endif
