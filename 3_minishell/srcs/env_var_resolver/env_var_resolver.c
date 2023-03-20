/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_resolver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:07:51 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/10 13:07:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var_resolver.h"

static t_input_type	get_input_type(char input)
{
	if (ft_isalnum(input) || input == '_')
		return (ALNUM);
	else if (input == '$')
		return (DOLLAR);
	else if (input == '\'')
		return (SQUOTE);
	else if (input == '\"')
		return (DQUOTE);
	else if (input == '\0')
		return (NULL_CH);
	else
		return (SPECIAL);
}

static t_transition	get_transition(t_evr_state state, t_input_type input)
{
	static t_transition	transitions[SIZE_OF_STATE - 2][SIZE_OF_INPUT] = {
	[EVR_NORMAL] = {evr_normal_to_normal, evr_normal_to_env,
		evr_normal_to_other, evr_normal_to_other, evr_normal_to_normal,
		evr_normal_to_other},
	[EVR_ENV] = {evr_env_take_alnum, evr_env_try_replace, evr_env_take_squote,
		evr_env_take_dquote, evr_env_try_replace, evr_env_to_end},
	[EVR_SQUOTE] = {evr_squote, evr_squote, evr_squote, evr_squote, evr_squote,
		NULL},
	[EVR_DQUOTE] = {evr_dquote_to_dquote, evr_dquote_to_env,
		evr_dquote_to_dquote, evr_dquote_to_normal, evr_dquote_to_dquote, NULL}
	};

	return (transitions[state][input]);
}

char	*resolve_word(char *str, t_tree *envs)
{
	t_evr			evr;
	t_input_type	input_type;

	evr.prev_state = EVR_NORMAL;
	evr.state = EVR_NORMAL;
	evr.start = str;
	evr.result = NULL;
	evr.envs = envs;
	while (TRUE)
	{
		input_type = get_input_type(*str);
		if (get_transition(evr.state, input_type) == NULL)
			break ;
		evr.state = (get_transition(evr.state, input_type))(&evr, str);
		if (evr.state == EVR_END)
			break ;
		str++;
	}
	if (evr.state != EVR_END)
		return (NULL);
	return (evr.result);
}

_Bool	resolve_env_vars(t_list *tokens, t_tree *envs)
{
	char	*temp_str;
	t_node	*cur_token;
	t_node	*temp;

	if (tokens == NULL)
		return (FALSE);
	cur_token = tokens->head;
	while (cur_token != NULL)
	{
		if (cur_token->data.type == WORD)
		{
			temp_str = cur_token->data.str;
			cur_token->data.str = resolve_word(temp_str, envs);
			free(temp_str);
		}
		temp = cur_token->next;
		if (cur_token->data.str == NULL)
			erase_node(tokens, cur_token);
		cur_token = temp;
	}
	return (TRUE);
}
