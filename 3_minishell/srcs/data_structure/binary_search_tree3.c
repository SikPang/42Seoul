/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:34:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/27 14:29:32 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

static void	destroy_tree_ev_recur(t_fruit *cur)
{
	if (cur == NULL)
		return ;
	destroy_tree_ev_recur(cur->lchild);
	destroy_tree_ev_recur(cur->rchild);
	free_fruit(cur);
}

void	destroy_tree_ev(t_tree **tree)
{
	destroy_tree_ev_recur((*tree)->root);
	free(*tree);
	*tree = NULL;
}
