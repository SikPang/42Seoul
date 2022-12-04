/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song <song@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:35:09 by song              #+#    #+#             */
/*   Updated: 2022/12/04 21:48:10 by song             ###   ########.fr       */
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
char	*get_next_line(int fd);

#endif
