# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/01/13 20:55:58 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCS	= ./sort/sort.h \
		./data_structure/deque.h \
		./data_structure/queue.h \
		./data_structure/array.h \
		./utility/utility.h
SRCS	= main.c \
		command.c \
		command_util.c \
		./sort/small_sort.c \
		./sort/radix_sort.c \
		./sort/main_sort.c \
		./data_structure/deque.c \
		./data_structure/deque2.c \
		./data_structure/queue.c \
		./data_structure/array.c \
		./utility/convert.c \
		./utility/error_exit.c \
		./utility/ft_split.c \
		./utility/ft_atoi.c \
		./utility/ft_calloc.c
OBJS	= $(SRCS:.c=.o)
GCH		= $(INCS:.h=.h.gch)

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

all		: $(NAME)
	make clean

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)
	rm -f $(GCH)

fclean	: 
	make clean
	rm -f $(NAME)

re		: 
	make fclean
	make all

.PHONY	: all clean fclean re