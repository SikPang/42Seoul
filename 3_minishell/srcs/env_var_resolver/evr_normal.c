/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evr_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:30:30 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/28 11:34:33 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var_resolver.h"

// input : alnum, special
t_evr_state	evr_normal_to_normal(t_evr *evr, char *input)
{
	(void)evr;
	(void)input;
	return (EVR_NORMAL);
}

// input : $
t_evr_state	evr_normal_to_env(t_evr *evr, char *input)
{
	evr->prev_state = EVR_NORMAL;
	if (evr->start != NULL)
		evr->result = ft_strjoin_free(evr->result,
				ft_substr(evr->start, 0, input - evr->start), FALSE);
	evr->start = input;
	return (EVR_ENV);
}

// input : \', \", \0
t_evr_state	evr_normal_to_other(t_evr *evr, char *input)
{
	if (*input == '\'')
	{
		evr->prev_state = EVR_SQUOTE;
		return (evr->prev_state);
	}
	else if (*input == '\"')
	{
		evr->prev_state = EVR_DQUOTE;
		return (evr->prev_state);
	}
	else if (*input == '\0')
	{
		if (evr->start != NULL)
			evr->result = ft_strjoin_free(evr->result,
					ft_substr(evr->start, 0, input - evr->start), FALSE);
		return (EVR_END);
	}
	return (EVR_NORMAL);
}
