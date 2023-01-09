# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/01/09 16:32:00 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCS	= push_swap.h \
		radix_sort.h \
		./data_structure/deque.h \
		./data_structure/queue.h \
		./data_structure/array.h \
		./utility/utility.h
SRCS	= main.c \
		push_swap.c \
		radix_sort.c \
		command.c \
		./data_structure/deque.c \
		./data_structure/deque2.c \
		./data_structure/queue.c \
		./data_structure/array.c \
		./utility/convert.c \
		./utility/ft_split.c \
		./utility/ft_atoi.c \
		./utility/ft_calloc.c
OBJS	= $(SRCS:.c=.o)
GCH		= $(INCS:.h=.h.gch)

CC		= gcc
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