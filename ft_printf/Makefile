# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2022/12/10 14:41:17 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= -srcu

INC		= ft_printf.h
SRCS	= ft_printf.c \
		print_char.c \
		print_str.c \
		print_decimal.c \
		print_hex.c \
		print_address.c

OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o		: %.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean	:
	rm -f $(OBJS)

fclean	: 
	make clean
	rm -f $(NAME)

re		: 
	make fclean
	make all

.PHONY : all clean fclean re
