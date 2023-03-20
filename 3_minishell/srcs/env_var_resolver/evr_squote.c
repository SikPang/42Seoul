/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evr_squote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:29:15 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/24 15:10:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var_resolver.h"

t_evr_state	evr_squote(t_evr *evr, char *input)
{
	(void)evr;
	if (*input == '\'')
	{
		evr->prev_state = EVR_NORMAL;
		return (EVR_NORMAL);
	}
	return (evr->state);
}

// env -> input : alnum
t_evr_state	evr_env_take_alnum(t_evr *evr, char *input)
{
	(void)evr;
	(void)input;
	return (EVR_ENV);
}
