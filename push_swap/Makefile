# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2022/12/27 19:07:12 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCS	= push_swap.h \
		deque.h \
		libft.h \
		ft_printf.h
SRCS	= main.c \
		push_swap.c \
		deque.c \
		command.c \
		ft_split.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_printf.c \
		print_str.c \
		print_decimal.c \
		print_hex.c
OBJS	= $(SRCS:.c=.o)
GCH		= $(INCS:.h=.h.gch)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o		: %.c
	$(CC) $(CFLAGS) -c $<

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