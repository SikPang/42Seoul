/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:01:15 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/10 14:00:39 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

#define INTEGER_MAX 2147483647

static _Bool	is_valid_argument(char *arg)
{
	int	base;
	int	sign;

	sign = 1;
	if (*arg == '-' || *arg == '+')
		sign = 1 - 2 * (*arg++ == '-');
	if (*arg == '\0')
		return (0);
	base = 0;
	while (*arg != '\0')
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		if (base > INTEGER_MAX / 10
			|| (base == INTEGER_MAX / 10
				&& ((*arg > '7' && sign == 1) || (*arg > '8' && sign == -1))))
			return (0);
		base = base * 10 + (*arg - '0');
		arg++;
	}
	return (1);
}

static void	check_numeric(char *str, _Bool is_paren)
{
	if (*str == '\0')
	{
		if (is_paren)
			write(2, "exit\n", 5);
		print_err("minish: exit: ", str, ": numeric argument required\n");
		exit(NUM_REQUIRED);
	}
	if (!is_valid_argument(str))
	{
		if (is_paren)
			write(2, "exit\n", 5);
		print_err("minish: exit: ", str, ": numeric argument required\n");
		exit(NUM_REQUIRED);
	}
}

int	cmd_exit(char **args, t_tree *envs, _Bool is_paren)
{
	int		idx;

	(void)envs;
	idx = 0;
	while (args[idx] != NULL)
	{
		if (idx >= 1)
		{
			print_err("minish: exit: ", "", "too many arguments\n");
			return (ARG_ERROR);
		}
		check_numeric(args[idx], is_paren);
		++idx;
	}
	if (is_paren)
		write(2, "exit\n", 5);
	if (*args == NULL)
		exit(g_our_first_global_variable_it_has_signal_and_i_am_happy);
	exit(ft_atoi(*args));
	return (SUCCESS);
}
