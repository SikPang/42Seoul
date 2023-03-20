/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:27:51 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/10 13:33:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

static t_token	is_operator(char *str)
{
	const char	*operator[] = {"<<", ">>", "<", ">", "|", NULL};
	const int	oper_len[5] = {2, 2, 1, 1, 1};
	int			i;

	i = 0;
	while (operator[i] != NULL)
	{
		if (!ft_strncmp(operator[i], str, oper_len[i]))
			return ((t_token){i, ft_strdup((char *)operator[i])});
		++i;
	}
	return ((t_token){FAIL, 0});
}

static _Bool	is_quote(t_list *list, char *str)
{
	if ((list->in_quote == DOUBLE && *str != '\"')
		|| (list->in_quote == SINGLE && *str != '\''))
		return (TRUE);
	if ((list->in_quote == DOUBLE && *str == '\"')
		|| (list->in_quote == SINGLE && *str == '\''))
	{
		list->in_quote = NONE;
		return (TRUE);
	}
	if (list->in_quote == NONE)
	{
		if (*str == '\"')
		{
			list->in_quote = DOUBLE;
			return (TRUE);
		}
		else if (*str == '\'')
		{
			list->in_quote = SINGLE;
			return (TRUE);
		}
	}
	return (FALSE);
}

static t_list	*check_quote_match(t_list *list)
{
	if (list->in_quote != NONE)
	{
		destroy_list(&list);
		return (NULL);
	}
	return (list);
}

t_list	*tokenize(char *str)
{
	t_list	*list;
	char	*start;
	t_token	tmp_token;

	list = init_list();
	start = str;
	--str;
	while (*(++str) != '\0')
	{
		if (is_quote(list, str))
			continue ;
		tmp_token = is_operator(str);
		if ((tmp_token.type != FAIL || *str == ' ') && start != str)
			push_back(list, (t_token){WORD, ft_substr(start, 0, str - start)});
		if (tmp_token.type != FAIL)
		{
			push_back(list, tmp_token);
			str += ft_strlen(tmp_token.str) - 1;
		}
		if (tmp_token.type != FAIL || *str == ' ')
			start = str + 1;
	}
	if (start != str)
		push_back(list, (t_token){WORD, ft_substr(start, 0, str - start)});
	return (check_quote_match(list));
}
