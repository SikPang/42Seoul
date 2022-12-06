/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:35:09 by song              #+#    #+#             */
/*   Updated: 2022/12/06 17:38:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
	char	*buf;
}	t_list;

t_node_	*find_node(t_list *list, int fd, int check);
t_node_	*push_back(t_list *list, int fd);
void	delete_node(t_list *list, int fd);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2, ssize_t byte);
int		add_to_data(t_list *list, t_node_ *node, ssize_t byte);
char	*get_last(t_node_ *node, t_list *list, int fd, ssize_t nl_index);
char	*get_result(t_node_ *node, ssize_t nl_index);
ssize_t	find_new_line(t_node_ *node, t_list *list);
char	*get_next_line(int fd);

#endif
