/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:39:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/02 19:33:44 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

static _Bool	need_to_add_string(t_in_quote *in_quote_ref, char *str)
{
	if (((*in_quote_ref) == DOUBLE && *str == '\"')
		|| ((*in_quote_ref) == SINGLE && *str == '\''))
	{
		(*in_quote_ref) = NONE;
		return (TRUE);
	}
	else if ((*in_quote_ref) == NONE
		&& (*str == '\'' || *str == '\"'))
	{
		if (*str == '\"')
			(*in_quote_ref) = DOUBLE;
		else
			(*in_quote_ref) = SINGLE;
		return (TRUE);
	}
	else if (*str == '\0')
	{
		return (TRUE);
	}
	return (FALSE);
}

char	*del_quote(char *str)
{
	t_in_quote	in_quote;
	char		*result;
	char		*start;

	in_quote = NONE;
	result = NULL;
	start = str;
	while (TRUE)
	{
		if (need_to_add_string(&in_quote, str))
		{
			result = ft_strjoin_free(result, ft_substr(start, 0, str - start),
					FALSE);
			start = str + (*str != '\0');
		}
		if (*str++ == '\0')
			break ;
	}
	if (result == NULL)
		return (ft_strdup(""));
	return (result);
}

_Bool	del_quote_in_token(t_list *tokens)
{
	t_node	*cur;
	char	*temp;

	cur = tokens->head;
	while (cur != NULL)
	{
		temp = cur->data.str;
		cur->data.str = del_quote(temp);
		free(temp);
		cur = cur->next;
	}
	return (TRUE);
}

_Bool	is_redirection(t_node *token)
{
	t_token_type	tk_type;

	tk_type = token->data.type;
	return (tk_type == DGREAT || tk_type == GREAT || tk_type == LESS);
}
