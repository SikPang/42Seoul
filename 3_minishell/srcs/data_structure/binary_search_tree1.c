/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:03:39 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/10 14:06:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

static _Bool	insert_env_recur(t_fruit *cur, t_fruit *new)
{
	int		cmp;

	if (cur == NULL)
		return (TRUE);
	cmp = ft_strcmp(cur->data.ev.name, new->data.ev.name);
	if (cmp < 0)
	{
		if (insert_env_recur(cur->rchild, new))
			cur->rchild = new;
	}
	else
	{
		if (insert_env_recur(cur->lchild, new))
			cur->lchild = new;
	}
	return (FALSE);
}

void	insert_env(t_tree *tree, t_env_var ev)
{
	t_fruit	*new;
	t_fruit	*cur;

	if (tree->size >= 5000)
		return ;
	cur = find_env(tree, ev.name);
	if (cur == NULL)
	{
		new = (t_fruit *)ft_calloc(1, sizeof(t_fruit));
		new->data.ev = (t_env_var){ev.name, ev.value};
		if (tree->root == NULL)
			tree->root = new;
		else
			insert_env_recur(tree->root, new);
		++(tree->size);
	}
	else if (ev.value != NULL)
	{
		free(cur->data.ev.name);
		free(cur->data.ev.value);
		cur->data.ev = (t_env_var){ev.name, ev.value};
	}
	else
		free(ev.name);
}

static t_env_var	get_min_ev(t_fruit *cur)
{
	while (cur->lchild != NULL)
		cur = cur->lchild;
	return (cur->data.ev);
}

static t_fruit	*terminate_env(t_tree *tree, t_fruit *cur)
{
	t_fruit	*temp;

	--(tree->size);
	if (tree->size == 0)
		tree->root = NULL;
	if (cur->rchild == NULL)
	{
		temp = cur->lchild;
		if (cur == tree->root)
			tree->root = temp;
		free_fruit(cur);
		return (temp);
	}
	else
	{
		temp = cur->rchild;
		if (cur == tree->root)
			tree->root = temp;
		free_fruit(cur);
		return (temp);
	}
}

t_fruit	*erase_env(t_tree *tree, t_fruit *cur, char *name)
{
	int			cmp;
	t_env_var	temp_ev;

	if (cur == NULL)
		return (NULL);
	cmp = ft_strcmp(cur->data.ev.name, name);
	if (cmp < 0)
		cur->rchild = erase_env(tree, cur->rchild, name);
	else if (cmp > 0)
		cur->lchild = erase_env(tree, cur->lchild, name);
	else
	{
		if (cur->lchild == NULL || cur->rchild == NULL)
			return (terminate_env(tree, cur));
		temp_ev = get_min_ev(cur->rchild);
		free(cur->data.ev.name);
		free(cur->data.ev.value);
		cur->data.ev = (t_env_var){ft_strdup(temp_ev.name),
			ft_strdup(temp_ev.value)};
		cur->rchild = erase_env(tree, cur->rchild, temp_ev.name);
	}
	return (cur);
}
