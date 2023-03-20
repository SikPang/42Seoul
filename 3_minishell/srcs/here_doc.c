/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:11:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/07 13:27:45 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "here_doc.h"

void	unlink_tmp_files(t_list **list)
{
	t_node	*cur;

	cur = (*list)->head;
	while (cur != NULL)
	{
		if (unlink(cur->data.str) == -1)
			handle_error_and_exit(ERROR_UNLINK);
		cur = cur->next;
	}
	destroy_list(list);
}

void	change_tokens(t_node *cur_token, char *tmp_file_name)
{
	free(cur_token->next->data.str);
	free(cur_token->data.str);
	cur_token->data.type = LESS;
	cur_token->data.str = ft_strdup("<");
	cur_token->next->data.str = tmp_file_name;
}

char	*open_temp_file(int *fd, t_list *tmp_file_list)
{
	char	*file_name;
	int		rand_fd;
	int		rand_num;
	long	value;

	rand_fd = open("/dev/random", O_RDONLY);
	if (rand_fd == -1)
		handle_error_and_exit(ERROR_OPEN);
	value = read(rand_fd, &rand_num, sizeof(rand_num));
	if (value == -1)
		handle_error_and_exit(ERROR_READ);
	close(rand_fd);
	file_name = ft_strjoin_free(ft_strdup("/tmp/"), ft_itoa(rand_num), FALSE);
	*fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
		handle_error_and_exit(ERROR_OPEN);
	push_back(tmp_file_list, (t_token){WORD, ft_strdup(file_name)});
	return (file_name);
}

void	readline_and_write(int fd, char *eof)
{
	char	*line;
	char	*processed_eof;

	line = NULL;
	processed_eof = del_quote(eof);
	while (TRUE)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, processed_eof) == 0)
		{
			free(line);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) == -1)
			handle_error_and_exit(ERROR_WRITE);
		if (write(fd, "\n", 1) == -1)
			handle_error_and_exit(ERROR_WRITE);
		free(line);
	}
	free(processed_eof);
}

int	here_doc(t_list *tokens, t_list *tmp_file_list)
{
	t_node	*token;
	char	*tmp_file_name;
	int		tmp_fd;
	int		tmp_count;

	if (tokens == NULL)
		return (0);
	token = tokens->head;
	tmp_count = 0;
	while (token != NULL)
	{
		if (token->data.type == DLESS)
		{
			if (token->next == NULL || token->next->data.type != WORD)
				return (-1);
			tmp_file_name = open_temp_file(&tmp_fd, tmp_file_list);
			readline_and_write(tmp_fd, token->next->data.str);
			change_tokens(token, tmp_file_name);
			close(tmp_fd);
			++tmp_count;
		}
		token = token->next;
	}
	return (tmp_count);
}
