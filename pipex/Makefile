# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/02/03 15:51:46 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

MANDATORY	= .man
BONUS		= .bonus

SRCS_DIR	= ./Mandatory/
B_SRCS_DIR	= ./Bonus/

SRCS_FILE	= main.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./utility/error_exit.c \
			./utility/ft_strncmp.c \
			./utility/ft_calloc.c \
			./utility/ft_split.c
B_SRCS_FILE	= main.c

SRCS	= $(addprefix $(SRCS_DIR), $(SRCS_FILE))
B_SRCS	= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILE))

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

.PHONY	: all clean fclean re