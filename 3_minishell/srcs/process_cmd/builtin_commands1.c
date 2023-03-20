/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:28:11 by sokwon            #+#    #+#             */
/*   Updated: 2023/03/09 17:06:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"
#include "global_var.h"
#include <stdio.h>

void	print_err(char *str1, char *str2, char *str3)
{
	if (str2 == NULL)
	{
		if (write(2, "minish: cd: OLDPWD not set\n", 27) == -1)
			handle_error_and_exit(ERROR_WRITE);
		return ;
	}
	if (write(2, str1, ft_strlen(str1)) == -1)
		handle_error_and_exit(ERROR_WRITE);
	if (write(2, str2, ft_strlen(str2)) == -1)
		handle_error_and_exit(ERROR_WRITE);
	if (write(2, str3, ft_strlen(str3)) == -1)
		handle_error_and_exit(ERROR_WRITE);
}

int	cmd_cd(char **args, t_tree *envs, _Bool is_paren)
{
	char	*cwd;
	char	*wanted_path;

	(void)is_paren;
	wanted_path = *args;
	if (*args == NULL)
		wanted_path = find_env(envs, "HOME")->data.ev.value;
	else if (ft_strcmp(*args, "-") == 0)
		wanted_path = find_env(envs, "OLDPWD")->data.ev.value;
	cwd = getcwd(NULL, 0);
	if (chdir(wanted_path) == -1)
	{
		print_err("minish: cd: ", wanted_path, ": No such file or directory\n");
		free(cwd);
		return (ARG_ERROR);
	}
	if (ft_strcmp(*args, "-") == 0)
		cmd_pwd(args, envs, is_paren);
	insert_env(envs, (t_env_var){ft_strdup("OLDPWD"), cwd});
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		handle_error_and_exit(ERROR_MALLOC);
	insert_env(envs, (t_env_var){ft_strdup("PWD"), cwd});
	g_our_first_global_variable_it_has_signal_and_i_am_happy = 0;
	return (SUCCESS);
}

_Bool	is_valid_env_name(char *name)
{
	if (ft_isdigit(*name) || *name == '\0')
		return (FALSE);
	while (*name != '\0')
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (FALSE);
		name++;
	}
	return (TRUE);
}

int	cmd_export(char **args, t_tree *envs, _Bool is_paren)
{
	int			exit_code;
	t_env_var	env;

	(void)is_paren;
	exit_code = SUCCESS;
	if (*args == NULL)
	{
		print_envs(envs->root, TRUE);
		return (exit_code);
	}
	while (*args != NULL)
	{
		env = get_env_var(*args);
		if (is_valid_env_name(env.name))
			insert_env(envs, env);
		else
		{
			free(env.name);
			free(env.value);
			print_err("minish: export: `", *args, "\': not a valid identifier\n");
			exit_code = ARG_ERROR;
		}
		++args;
	}
	return (exit_code);
}

int	mini_execve(char **full_cmd, t_tree *envs, _Bool is_paren)
{
	const char			*cmd_name[] = {"echo", "cd", "pwd", "export",
		"unset", "env", "exit"};
	const t_cmd_func	cmd_func[] = {cmd_echo, cmd_cd, cmd_pwd, cmd_export,
		cmd_unset, cmd_env, cmd_exit};
	unsigned long		idx;

	idx = -1;
	while (++idx < sizeof(cmd_name) / sizeof(cmd_name[0]))
	{
		if (ft_strcmp(full_cmd[0], cmd_name[idx]) == 0)
			return ((cmd_func[idx])(full_cmd + 1, envs, is_paren));
	}
	return (-1);
}
