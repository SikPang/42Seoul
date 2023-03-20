/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evr_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:30:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/06 16:09:19 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var_resolver.h"
#include "global_var.h"

static void	replace_name_to_value(t_evr *evr, char *input)
{
	t_fruit	*tmp;
	char	*name;
	char	*value;

	value = NULL;
	if (evr->start == NULL)
	{
		evr->start = input;
		return ;
	}
	if (input - evr->start > 1)
	{
		name = ft_substr(evr->start, 1, input - evr->start - 1);
		tmp = find_env(evr->envs, name);
		if (tmp)
			value = tmp->data.ev.value;
		free(name);
	}
	if (value)
		evr->result = ft_strjoin_free(evr->result, ft_strdup(value), FALSE);
	evr->start = input;
}

// input : \'
t_evr_state	evr_env_take_squote(t_evr *evr, char *input)
{
	replace_name_to_value(evr, input);
	if (evr->prev_state == EVR_SQUOTE)
		return (EVR_NORMAL);
	if (evr->prev_state == EVR_DQUOTE)
		return (evr->prev_state);
	else
		return (EVR_SQUOTE);
}

// input : \"
t_evr_state	evr_env_take_dquote(t_evr *evr, char *input)
{
	replace_name_to_value(evr, input);
	if (evr->prev_state == EVR_SQUOTE)
		return (evr->prev_state);
	if (evr->prev_state == EVR_DQUOTE)
		return (EVR_NORMAL);
	else
		return (EVR_DQUOTE);
}

// input : special, $
t_evr_state	evr_env_try_replace(t_evr *evr, char *input)
{
	char	*s_num;

	if (*input == '$')
	{
		replace_name_to_value(evr, input);
		return (evr->state);
	}
	if (*input == '?' && evr->start == input - 1)
	{
		s_num
			= ft_itoa(g_our_first_global_variable_it_has_signal_and_i_am_happy);
		evr->result = ft_strjoin_free(evr->result, s_num, FALSE);
		evr->start = input + 1;
	}
	else
		replace_name_to_value(evr, input);
	return (evr->prev_state);
}

// input : \0
t_evr_state	evr_env_to_end(t_evr *evr, char *input)
{
	if (evr->prev_state == EVR_SQUOTE || evr->prev_state == EVR_DQUOTE)
		return (EVR_FAIL);
	else
	{
		replace_name_to_value(evr, input);
		return (EVR_END);
	}
}
