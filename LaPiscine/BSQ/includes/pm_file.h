/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:00:19 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 11:00:49 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_FILE_H
# define PM_FILE_H

# include <fcntl.h>		//open(), O_RDONLY, O_NONBLOCK
# include <unistd.h>	//read(), close()
# include <stdlib.h>	//malloc(), free(), NULL
# include "queue.h"		//IS_EMPTY
# include "pm_mem.h"	//check_null_after_malloc(), occur_error()

# define BUFFER_SIZE		4096
# define UNIT_OF_MALLOC		64
# define MAX_BUFFER_SIZE	10485760
# define ERROR_OPEN			-1
# define END_OF_FILE		-1

typedef struct s_file	t_file;

struct s_file
{
	int		fd;
	char	*tmp_buffer;
	t_queue	*buffer;
	char	(*getc)(t_file *this);
	char	*(*get_line)(t_file *this);
};

// output : NULL (if no file), t_file pointer (else)
t_file	*new_t_file(char *file_name);
void	del_t_file(t_file *this);
// output : -1 (eof), char (else)
char	t_file_getc(t_file *this);
// output : NULL(there is no line break), char *(else)
char	*t_file_get_line(t_file *this);

#endif
