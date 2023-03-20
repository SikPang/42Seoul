/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:28:11 by sokwon            #+#    #+#             */
/*   Updated: 2023/03/14 16:20:24 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"
#include "global_var.h"

int	cmd_pwd(char **args, t_tree *envs, _Bool is_paren)
{
	char	*cwd;

	(void)is_paren;
	(void)args;
	(void)envs;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		handle_error_and_exit(ERROR_MALLOC);
	printf("%s\n", cwd);
	free(cwd);
	return (SUCCESS);
}

int	cmd_unset(char **args, t_tree *envs, _Bool is_paren)
{
	(void)is_paren;
	while (*args != NULL)
	{
		if (!is_valid_env_name(*args))
			print_err("minish: export: `", *args, "\': not a valid identifier\n");
		else
			erase_env(envs, envs->root, *args);
		++args;
	}
	return (SUCCESS);
}

int	cmd_env(char **args, t_tree *envs, _Bool is_paren)
{
	(void)is_paren;
	if (args[0] != NULL)
		return (ARG_ERROR);
	print_envs(envs->root, FALSE);
	return (SUCCESS);
}

static _Bool	is_n_option(char *str)
{
	if (*str++ == '-')
	{
		if (*str == '\0')
			return (FALSE);
		while (*str != '\0')
		{
			if (*str++ != 'n')
			{
				return (FALSE);
			}
		}
		return (TRUE);
	}
	return (FALSE);
}

int	cmd_echo(char **args, t_tree *envs, _Bool is_paren)
{
	_Bool	option_n;

	(void)envs;
	(void)is_paren;
	option_n = FALSE;
	while (*args != NULL)
	{
		if (is_n_option(*args))
			option_n = TRUE;
		else
			break ;
		++args;
	}
	while (*args != NULL)
	{
		ft_putstr_fd(*args, 1);
		if (*(args + 1) != NULL)
			ft_putstr_fd(" ", 1);
		++args;
	}
	if (!option_n)
		ft_putstr_fd("\n", 1);
	return (SUCCESS);
}
