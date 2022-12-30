# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2022/12/30 18:20:05 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCS	= push_swap.h \
		deque.h \
		./utility/utility.h \
		./ft_printf/ft_printf.h
SRCS	= main.c \
		push_swap.c \
		deque.c \
		command.c \
		./utility/ft_split.c \
		./utility/ft_atoi.c \
		./utility/ft_calloc.c \
		./ft_printf/ft_printf.c \
		./ft_printf/print_str.c \
		./ft_printf/print_decimal.c \
		./ft_printf/print_hex.c
OBJS	= $(SRCS:.c=.o)
GCH		= $(INCS:.h=.h.gch)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

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