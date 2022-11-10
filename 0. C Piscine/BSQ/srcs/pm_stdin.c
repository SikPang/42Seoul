/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:43:42 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 12:29:53 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pm_stdin.h"

t_stdin	*new_t_stdin(void)
{
	t_stdin	*this;

	this = (t_stdin *)malloc(sizeof(t_stdin));
	check_null_after_malloc(this);
	this->tmp_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	check_null_after_malloc(this->tmp_buffer);
	this->buffer = new_t_queue(BUFFER_SIZE);
	this->getc = t_stdin_getc;
	this->gets = t_stdin_gets;
	return (this);
}

void	del_t_stdin(t_stdin *this)
{
	del_t_queue(this->buffer);
	free(this->tmp_buffer);
	free(this);
}

char	t_stdin_getc(t_stdin *this)
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
	n_bytes_read = read(STDIN_FILENO, tmp_buf, BUFFER_SIZE);
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

int	realloc_stdin_buffer(unsigned int *buffer_size, char **buffer)
{
	*buffer_size *= 2;
	if (*buffer_size > MAX_BUFFER_SIZE)
		return (occur_error(*buffer));
	*buffer = (char *)pm_realloc(*buffer, *buffer_size / 2, *buffer_size);
	check_null_after_malloc(*buffer);
	return (1);
}

char	*t_stdin_gets(t_stdin *this)
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
		if (idx == buffer_size - 1
			&& !realloc_stdin_buffer(&buffer_size, &buffer))
			return (NULL);
		c = this->getc(this);
		if (c == END_OF_FILE || c == '\n')
			break ;
		buffer[idx++] = c;
	}
	buffer[idx] = '\0';
	return (buffer);
}
