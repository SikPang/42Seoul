/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:35:09 by song              #+#    #+#             */
/*   Updated: 2022/12/05 17:59:02 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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

t_node_	*find_node(t_list *list, int fd);
t_node_	*push_back(t_list *list, int fd);
void	delete_node(t_list *list, int fd);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2, ssize_t byte);
void	add_to_data(t_node_ *node, char *buf, ssize_t byte);
char	*get_result(t_node_ *node, ssize_t new_line_index,
			t_list *list, int fd);
ssize_t	find_new_line(t_node_ *node);
char	*get_next_line(int fd);

#endif
