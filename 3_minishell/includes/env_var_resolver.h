/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_resolver.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:08:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/03 18:11:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_RESOLVER_H
# define ENV_VAR_RESOLVER_H

# include "enum.h"
# include "list.h"
# include "binary_search_tree.h"
# include "libft.h"

typedef struct s_env_var_resolver
{
	t_tree		*envs;
	t_evr_state	prev_state;
	t_evr_state	state;
	char		*start;
	char		*result;
}				t_evr;

typedef t_evr_state	(*t_transition)(t_evr *, char *);

char		*resolve_word(char *str, t_tree *envs);
_Bool		resolve_env_vars(t_list *tokens, t_tree *envs);

t_evr_state	evr_dquote_to_dquote(t_evr *evr, char *input);
t_evr_state	evr_dquote_to_env(t_evr *evr, char *input);
t_evr_state	evr_dquote_to_normal(t_evr *evr, char *input);

t_evr_state	evr_env_take_squote(t_evr *evr, char *input);
t_evr_state	evr_env_take_dquote(t_evr *evr, char *input);
t_evr_state	evr_env_take_alnum(t_evr *evr, char *input);
t_evr_state	evr_env_try_replace(t_evr *evr, char *input);
t_evr_state	evr_env_to_end(t_evr *evr, char *input);

t_evr_state	evr_normal_to_normal(t_evr *evr, char *input);
t_evr_state	evr_normal_to_env(t_evr *evr, char *input);
t_evr_state	evr_normal_to_other(t_evr *evr, char *input);

t_evr_state	evr_squote(t_evr *evr, char *input);

#endif
