/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:11:47 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/01 18:26:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include <stdlib.h>
# include <readline/readline.h>
# include <unistd.h>
# include "list.h"
# include "fcntl.h"
# include "libft.h"
# include "enum.h"
# include "error_handler.h"
# include "parsing_utils.h"

int		here_doc(t_list *tokens, t_list *tmp_file_list);
void	unlink_tmp_files(t_list **list);

#endif
