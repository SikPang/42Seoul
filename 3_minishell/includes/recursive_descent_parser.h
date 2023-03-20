/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_parser.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:43:56 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/03 17:18:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSIVE_DESCENT_PARSER_H
# define RECURSIVE_DESCENT_PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include "list.h"
# include "enum.h"
# include "error_handler.h"
# include "libft.h"
# include "parsing_utils.h"

t_list	*rdp_start(t_node *start, t_node *end);
_Bool	rdp_pipe(t_list *parse_que, t_node *start, t_node *end);
_Bool	rdp_command(t_list *parse_que, t_node *start, t_node *end);
_Bool	rdp_cmd_prefix(t_list *parse_que, t_node *start, t_node *end);
_Bool	rdp_cmd_suffix(t_list *parse_que, t_node *start, t_node *end);
_Bool	rdp_io_redirect(t_list *parse_que, t_node *start, t_node *end);

#endif
