# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 22:52:14 by sokwon            #+#    #+#              #
#    Updated: 2022/10/20 11:30:47 by sokwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq

INCS		= ./includes/
SRCS	= ./srcs/main.c ./srcs/queue.c ./srcs/ft_putstr.c \
		  ./srcs/pm_mem.c ./srcs/pm_file.c \
		  ./srcs/ft_str.c ./srcs/ft_atoi.c \
		  ./srcs/map.c ./srcs/map_parser.c \
		  ./srcs/find_square.c ./srcs/split.c \
		  ./srcs/pm_stdin.c
OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

all		: $(NAME) 

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
