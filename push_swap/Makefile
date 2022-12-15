# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2022/12/10 15:55:17 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= -srcu

INC		= push_swap.h \
		deque.h \
		libft.h \
		ft_printf.h
SRCS	= push_swap.c \
		deque.c \
		command.c \
		ft_split.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_printf.c \
		print_str.c \
		print_decimal.c \
		print_hex.c

GCH		= $(INC:.h=.h.gch)
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS) $(GCH)
	$(AR) $(ARFLAGS) $@ $?

%.o		: %.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean	:
	rm -f $(OBJS)
	rm -f $(GCH)

fclean	: 
	make clean
	rm -f $(NAME)

re		: 
	make fclean
	make all

.PHONY : all clean fclean re
