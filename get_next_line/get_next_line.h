/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:35:09 by song              #+#    #+#             */
/*   Updated: 2022/12/05 14:29:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
	ssize_t			start_index;
	int				fd;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}	t_list;

t_node	*find_node(t_list *list, int fd);
t_node	*push_back(t_list *list, int fd, char *data);
void	erase_node(t_list *list, int fd);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2, ssize_t byte);
void	add_to_data(t_node *node, char *buf, ssize_t byte);
char	*get_result(t_node *node, ssize_t new_line_index, ssize_t byte);
ssize_t	find_new_line(t_node *node);
char	*get_next_line(int fd);

#endif
