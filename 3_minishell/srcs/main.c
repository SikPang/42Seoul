/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:57:17 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/10 14:20:20 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "env_var_utils.h"
#include "env_var_resolver.h"
#include "enum.h"
#include "tokenize.h"
#include "here_doc.h"
#include "recursive_descent_parser.h"
#include "builtin_commands.h"
#include "execute_cmds.h"
#include "global_var.h"
#include "signal_handler.h"

static void	syntax_error(void)
{
	g_our_first_global_variable_it_has_signal_and_i_am_happy = SYNTAX_ERROR;
	printf("minish: syntax error\n");
}

static void	free_all(char *input, t_list **tokens,
	t_list **tmp_file_list, t_list **parse_que)
{
	free(input);
	destroy_list(tokens);
	destroy_list(parse_que);
	unlink_tmp_files(tmp_file_list);
}

static t_null	input_null_handler(char *input, t_list **tokens,
	t_list **tmp_file_list, t_list **parse_que)
{
	if (input == NULL)
	{
		printf("exit\n");
		free_all(input, tokens, tmp_file_list, parse_que);
		return (NULL_POINTER);
	}
	else if (*input == '\0')
	{
		free_all(input, tokens, tmp_file_list, parse_que);
		return (NULL_CHAR);
	}
	else
		add_history(input);
	return (NOT_NULL);
}

void	read_freaking_line(t_tree *envs, t_list *tokens,
	t_list *tmp_file_list, t_list *parse_que)
{
	char	*input;
	t_null	id;

	while (TRUE)
	{
		tmp_file_list = init_list();
		signal(SIGQUIT, SIG_IGN);
		input = readline("minish-1.0$ ");
		set_signal_policy_in_paren();
		id = input_null_handler(input, &tokens, &tmp_file_list, &parse_que);
		if (id == NULL_POINTER)
			break ;
		if (id == NULL_CHAR)
			continue ;
		tokens = tokenize(input);
		if (here_doc(tokens, tmp_file_list) != -1)
			if (resolve_env_vars(tokens, envs) && del_quote_in_token(tokens))
				parse_que = rdp_start(tokens->head, tokens->tail);
		if (parse_que == NULL)
			syntax_error();
		else
			execute_cmds(envs, parse_que, FALSE);
		free_all(input, &tokens, &tmp_file_list, &parse_que);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_tree	*envs;
	t_list	*tokens;
	t_list	*tmp_file_list;
	t_list	*parse_que;

	set_signal_policy_in_paren();
	if (argc != 1 || argv[1] != NULL)
	{
		printf("minish: %s: No such file or directory\n", argv[1]);
		return (CMD_FAIL);
	}
	parse_que = NULL;
	tokens = NULL;
	tmp_file_list = NULL;
	envs = init_tree();
	dup_envs(envs, envp);
	read_freaking_line(envs, tokens, tmp_file_list, parse_que);
	destroy_tree_ev(&envs);
	return (g_our_first_global_variable_it_has_signal_and_i_am_happy);
}
