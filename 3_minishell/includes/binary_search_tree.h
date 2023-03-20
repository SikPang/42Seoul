/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:11:37 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/24 14:44:13 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_H
# define BINARY_SEARCH_TREE_H

# include "enum.h"
# include "error_handler.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

typedef union u_data
{
	t_env_var	ev;
}				t_data;

typedef struct s_fruit
{
	struct s_fruit	*lchild;
	struct s_fruit	*rchild;
	t_data			data;
}				t_fruit;

typedef struct s_tree
{
	t_fruit		*root;
	int			size;
}	t_tree;

t_tree	*init_tree(void);
void	insert_env(t_tree *tree, t_env_var ev);
t_fruit	*erase_env(t_tree *tree, t_fruit *cur, char *name);
t_fruit	*find_env(t_tree *tree, char *name);
void	free_fruit(t_fruit *fruit);
void	print_envs(t_fruit *cur, _Bool is_export);
void	destroy_tree_ev(t_tree **tree);

#endif
