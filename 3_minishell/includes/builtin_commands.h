/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:28:52 by sokwon            #+#    #+#             */
/*   Updated: 2023/03/10 13:50:08 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_COMMANDS_H
# define BUILTIN_COMMANDS_H

# include "libft.h"
# include "env_var_utils.h"
# include "env_var_resolver.h"
# include "parsing_utils.h"
# include "global_var.h"
# include <stdio.h>		// printf()
# include <unistd.h>	// getcwd(), chdir()

typedef _Bool	t_bool_type;
typedef int		(*t_cmd_func)(char **, t_tree *, t_bool_type);

_Bool	is_valid_env_name(char *name);
void	print_err(char *str1, char *str2, char *str3);
int		cmd_echo(char **args, t_tree *envs, _Bool is_paren);
int		cmd_cd(char **args, t_tree *envs, _Bool is_paren);
int		cmd_pwd(char **args, t_tree *envs, _Bool is_paren);
int		cmd_export(char **args, t_tree *envs, _Bool is_paren);
int		cmd_unset(char **args, t_tree *envs, _Bool is_paren);
int		cmd_env(char **args, t_tree *envs, _Bool is_paren);
int		cmd_exit(char **args, t_tree *envs, _Bool is_paren);
int		mini_execve(char **full_cmd, t_tree *envs, _Bool is_paren);

#endif
