/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:09:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/02 17:33:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_UTILS_H
# define ENV_VAR_UTILS_H

# include "binary_search_tree.h"
# include "tokenize.h"
# include "enum.h"
# include "error_handler.h"
# include "libft.h"

void		dup_envs(t_tree *envs, char **envp);
t_env_var	get_env_var(char *str);
char		**get_paths(t_tree *tree);
char		**get_envp(t_tree *tree);

#endif
