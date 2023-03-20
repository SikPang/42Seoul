/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:38:09 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/13 12:34:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"

static _Bool	is_paren(void)
{
	return (wait(NULL) != -1);
}

static void	sig_int_in_paren(int sig_num)
{
	(void)sig_num;
	g_our_first_global_variable_it_has_signal_and_i_am_happy = EXIT_ON_SIGNAL;
	if (is_paren())
	{
		write(2, "\r", 1);
		return ;
	}
	g_our_first_global_variable_it_has_signal_and_i_am_happy = ARG_ERROR;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	sig_quit_in_paren(int sig_num)
{
	const char	message[] = "Quit: 3\n";

	(void)sig_num;
	if (!is_paren())
		return ;
	g_our_first_global_variable_it_has_signal_and_i_am_happy
		= EXIT_ON_SIGNAL + 1;
	write(2, message, sizeof(message));
}

void	set_signal_policy_in_paren(void)
{
	signal(SIGINT, sig_int_in_paren);
	signal(SIGQUIT, sig_quit_in_paren);
}

void	set_signal_policy_in_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
