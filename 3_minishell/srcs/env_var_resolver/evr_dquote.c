/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evr_dquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:31:43 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/28 11:34:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var_resolver.h"

// input : alnum, special, \'
t_evr_state	evr_dquote_to_dquote(t_evr *evr, char *input)
{
	(void)evr;
	(void)input;
	return (evr->state);
}

// input : $
t_evr_state	evr_dquote_to_env(t_evr *evr, char *input)
{
	evr->prev_state = EVR_DQUOTE;
	evr->result = ft_strjoin_free(evr->result,
			ft_substr(evr->start, 0, input - evr->start), FALSE);
	evr->start = input;
	return (EVR_ENV);
}

// input : \"
t_evr_state	evr_dquote_to_normal(t_evr *evr, char *input)
{
	evr->prev_state = EVR_NORMAL;
	(void)input;
	return (EVR_NORMAL);
}
