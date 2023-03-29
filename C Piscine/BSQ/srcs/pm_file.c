/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:00:50 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 11:14:26 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pm_file.h"

t_file	*new_t_file(char *file_name)
{
	t_file	*this;
	int		fd;

	fd = open(file_name, O_RDONLY | O_NONBLOCK);
	if (fd == ERROR_OPEN)
		return (NULL);
	this = (t_file *)malloc(sizeof(t_file));
	check_null_after_malloc(this);
	this->tmp_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	check_null_after_malloc(this->tmp_buffer);
	this->fd = fd;
	this->buffer = new_t_queue(BUFFER_SIZE);
	this->getc = t_file_getc;
	this->get_line = t_file_get_line;
	return (this);
}

void	del_t_file(t_file *this)
{
	close(this->fd);
	del_t_queue(this->buffer);
	free(this->tmp_buffer);
	free(this);
}

char	t_file_getc(t_file *this)
{
	char	*tmp_buf;
	t_queue	*buf;
	int		n_bytes_read;
	char	c;

	tmp_buf = this->tmp_buffer;
	buf = this->buffer;
	c = buf->deque(buf);
	if (c != IS_EMPTY)
		return (c);
	n_bytes_read = read(this->fd, tmp_buf, BUFFER_SIZE);
	if (n_bytes_read == 0)
		return (END_OF_FILE);
	while (n_bytes_read > 0)
	{
		buf->enque(buf, *tmp_buf);
		tmp_buf++;
		n_bytes_read--;
	}
	return (buf->deque(buf));
}

int	realloc_buffer(unsigned int *buffer_size, char **buffer)
{
	*buffer_size *= 2;
	if (*buffer_size > MAX_BUFFER_SIZE)
		return (occur_error(*buffer));
	*buffer = (char *)pm_realloc(*buffer, *buffer_size / 2, *buffer_size);
	check_null_after_malloc(*buffer);
	return (1);
}

char	*t_file_get_line(t_file *this)
{
	char			*buffer;
	unsigned int	buffer_size;
	unsigned int	idx;
	char			c;

	buffer_size = UNIT_OF_MALLOC;
	buffer = (char *)malloc(sizeof(char) * buffer_size);
	check_null_after_malloc(buffer);
	idx = 0;
	while (1)
	{
		if (idx == buffer_size - 1 && !realloc_buffer(&buffer_size, &buffer))
			return (NULL);
		c = this->getc(this);
		if (c == END_OF_FILE)
			return ((void *)(unsigned long)occur_error(buffer));
		if (c == '\n')
			break ;
		buffer[idx++] = c;
	}
	buffer[idx] = '\0';
	return (buffer);
}
