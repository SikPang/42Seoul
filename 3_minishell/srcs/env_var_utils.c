/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:09:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/09 16:35:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var_utils.h"

t_env_var	get_env_var(char *str)
{
	char	*name;
	char	*value;
	int		i;

	i = 0;
	name = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
		{
			if (i != 0)
				name = ft_substr(str, 0, i);
			else
				name = ft_strdup("");
			if (str[i + 1] != '\0')
				value = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
			else
				value = ft_strdup("");
			return ((t_env_var){name, value});
		}
		++i;
	}
	return ((t_env_var){ft_strdup(str), NULL});
}

void	dup_envs(t_tree *envs, char **envp)
{
	t_env_var	cur_var;
	int			value;
	int			i;

	i = 0;
	while (envp[i] != NULL)
	{
		cur_var = get_env_var(envp[i]);
		if (ft_strcmp(cur_var.name, "SHLVL") == 0)
		{
			value = ft_atoi(cur_var.value);
			free(cur_var.value);
			cur_var.value = ft_itoa(value + 1);
		}
		else if (ft_strcmp(cur_var.name, "OLDPWD") == 0)
		{
			free(cur_var.value);
			cur_var.value = NULL;
		}
		insert_env(envs, cur_var);
		++i;
	}
}

char	**get_paths(t_tree *tree)
{
	char	**paths;
	t_fruit	*node;

	node = find_env(tree, "PATH");
	if (node == NULL)
	{
		paths = (char **)ft_calloc(2, sizeof(char *));
		paths[0] = ft_strdup("");
	}
	else
	{
		paths = ft_split(node->data.ev.value, ':');
		if (paths == NULL)
			handle_error_and_exit(ERROR_MALLOC);
	}
	return (paths);
}

static void	get_envp_recur(char **envp, int *idx_ref, t_fruit *cur)
{
	if (cur == NULL)
		return ;
	get_envp_recur(envp, idx_ref, cur->lchild);
	envp[*idx_ref] = ft_strjoin_free(ft_strjoin(cur->data.ev.name, "=", FALSE),
			ft_strdup(cur->data.ev.value), FALSE);
	(*idx_ref)++;
	get_envp_recur(envp, idx_ref, cur->rchild);
}

char	**get_envp(t_tree *tree)
{
	char	**envp;
	int		idx;

	envp = (char **)ft_calloc((tree->size + 1), sizeof(char *));
	idx = 0;
	get_envp_recur(envp, &idx, tree->root);
	return (envp);
}
