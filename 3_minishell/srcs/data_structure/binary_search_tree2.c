/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:27:19 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/03 16:33:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

t_tree	*init_tree(void)
{
	t_tree	*tree;

	tree = (t_tree *)malloc(sizeof(t_tree));
	if (tree == NULL)
		handle_error_and_exit(ERROR_MALLOC);
	tree->root = NULL;
	tree->size = 0;
	return (tree);
}

void	free_fruit(t_fruit *fruit)
{
	free(fruit->data.ev.name);
	free(fruit->data.ev.value);
	free(fruit);
}

t_fruit	*find_env(t_tree *envs, char *name)
{
	t_fruit	*cur;
	int		cmp;

	if (envs->root == NULL)
		return (NULL);
	cur = envs->root;
	while (cur != NULL && name != NULL)
	{
		cmp = ft_strcmp(cur->data.ev.name, name);
		if (cmp == 0)
			return (cur);
		else if (cmp < 0)
			cur = cur->rchild;
		else
			cur = cur->lchild;
	}
	return (NULL);
}

void	print_envs(t_fruit *cur, _Bool is_export)
{
	if (cur == NULL)
		return ;
	print_envs(cur->lchild, is_export);
	if (is_export == TRUE)
	{
		printf("declare -x ");
		if (cur->data.ev.value == NULL)
			printf("%s\n", cur->data.ev.name);
		else
			printf("%s=\"%s\"\n", cur->data.ev.name, cur->data.ev.value);
	}
	else
	{
		if (cur->data.ev.value != NULL)
			printf("%s=%s\n", cur->data.ev.name, cur->data.ev.value);
	}
	print_envs(cur->rchild, is_export);
}
