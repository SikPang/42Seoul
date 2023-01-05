/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_stdin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:40:27 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 10:26:13 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_STDIN_H
# define PM_STDIN_H

# include <unistd.h>	//read()
# include <stdlib.h>	//malloc(), free(), NULL
# include "queue.h"		//IS_EMPTY
# include "pm_mem.h"	//check_null_after_malloc()

# define BUFFER_SIZE		4096
# define UNIT_OF_MALLOC		64
# define MAX_BUFFER_SIZE	10485760
# define ERROR_OPEN			-1
# define END_OF_FILE		-1

typedef struct s_stdin	t_stdin;

struct s_stdin
{
	char	*tmp_buffer;
	t_queue	*buffer;
	char	(*getc)(t_stdin *this);
	char	*(*gets)(t_stdin *this);
};

// output : NULL (if no stdin), t_stdin pointer (else)
t_stdin	*new_t_stdin(void);
void	del_t_stdin(t_stdin *this);
// output : -1 (eof), char (else)
char	t_stdin_getc(t_stdin *this);
// output : NULL(there is no line break), char *(else)
char	*t_stdin_gets(t_stdin *this);

#endif
