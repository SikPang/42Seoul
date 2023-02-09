# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/02/09 19:53:20 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

MANDATORY	= .man
BONUS		= .bonus

SRCS_DIR	= ./Mandatory/
B_SRCS_DIR	= ./Bonus/

SRCS_FILE	= main \
			utils \
			./split/ft_split \
			./split/ft_split_util \
			./utility/error \
			./utility/ft_strncmp \
			./utility/ft_strncpy \
			./utility/ft_strlen \
			./utility/ft_strjoin
B_SRCS_FILE	= here_doc \
			./utility/ft_strcmp \
			./get_next_line/get_next_line \
			./get_next_line/get_next_line_utils

SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILE)))
B_SRCS	= $(addprefix $(B_SRCS_DIR), $(addsuffix _bonus.c, $(SRCS_FILE))) \
			$(addprefix $(B_SRCS_DIR), $(addsuffix _bonus.c, $(B_SRCS_FILE)))

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

CFLAGS	= #-Wall -Werror -Wextra

all		: $(MANDATORY)
	@touch $(MANDATORY)
	@rm -f $(BONUS)
	make clean

$(MANDATORY)	: $(OBJS)
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $^

bonus	: $(BONUS)
	@touch $(BONUS)
	@rm -f $(MANDATORY)
	make clean

$(BONUS)		: $(B_OBJS)
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean	:
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean	:
	make clean
	rm -f $(NAME)
	@rm -f $(BONUS)
	@rm -f $(MANDATORY)

re		:
	make fclean
	make all

.PHONY	: all bonus clean fclean re