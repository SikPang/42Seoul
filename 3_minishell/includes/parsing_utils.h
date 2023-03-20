/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:39:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/02 19:35:49 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H

# include "parsing_utils.h"
# include "libft.h"
# include "enum.h"
# include "list.h"

char	*del_quote(char *str);
_Bool	del_quote_in_token(t_list *tokens);
_Bool	is_redirection(t_node *token);

#endif
