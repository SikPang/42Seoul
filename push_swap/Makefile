# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/01/07 17:56:18 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCS	= push_swap.h \
		deque.h \
		queue.h \
		array.h \
		radix_sort.h \
		./utility/utility.h
SRCS	= main.c \
		push_swap.c \
		deque.c \
		queue.c \
		array.c \
		radix_sort.c \
		command.c \
		./utility/ft_split.c \
		./utility/ft_atoi.c \
		./utility/ft_calloc.c
OBJS	= $(SRCS:.c=.o)
GCH		= $(INCS:.h=.h.gch)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
# GCH 수정
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