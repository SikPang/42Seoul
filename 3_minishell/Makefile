# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:13:05 by kwsong            #+#    #+#              #
#    Updated: 2023/03/10 14:20:28 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

INC_DIR		= ./includes

SRCS_DIR	= ./srcs/

SRCS_FILE	= main \
			error_handler \
			env_var_utils \
			here_doc \
			global_var \
			signal_handler \
			/process_cmd/builtin_commands1 \
			/process_cmd/builtin_commands2 \
			/process_cmd/builtin_commands3 \
			/process_cmd/execute_cmds1 \
			/process_cmd/execute_cmds2 \
			/process_cmd/execute_cmds3 \
			/process_cmd/execute_cmds4 \
			/parsing/tokenize \
			/parsing/parsing_utils \
			/parsing/recursive_descent_parser1 \
			/parsing/recursive_descent_parser2 \
			/data_structure/list1 \
			/data_structure/list2 \
			/data_structure/binary_search_tree1 \
			/data_structure/binary_search_tree2 \
			/data_structure/binary_search_tree3  \
			/env_var_resolver/env_var_resolver \
			/env_var_resolver/evr_normal \
			/env_var_resolver/evr_env \
			/env_var_resolver/evr_squote \
			/env_var_resolver/evr_dquote

SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILE)))

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra
LFLAGS	= ${HOME}/.brew/opt/readline/lib
IFLAGS	= ${HOME}/.brew/opt/readline/include

all		: $(NAME)

$(NAME)	: $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $^ \
		-I$(INC_DIR)/ -I./libft/ \
		-Llibft/ -lft \
		-I$(IFLAGS)/ -L$(LFLAGS) -lreadline

%.o	: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)/ -I./libft/ -I$(IFLAGS)/

clean	:
	make -C libft/ fclean
	rm -f $(OBJS)

fclean	:
	make clean
	rm -f $(NAME)

re		:
	make fclean
	make all

.PHONY	: all clean fclean re
