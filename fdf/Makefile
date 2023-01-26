# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/01/26 22:37:11 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRCS	= main.c \
		event.c \
		./draw/color.c \
		./draw/bresenham.c \
		./draw/draw.c \
		./data_structure/list.c \
		./data_structure/llist.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./utility/error_exit.c \
		./utility/ft_split.c \
		./utility/ft_atoi.c \
		./utility/ft_calloc.c
OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Lmlx_mms -lmlx -framework OpenGL -framework AppKit 
# -Wall -Werror -Wextra

all		: $(NAME)
	make clean

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean	:
	rm -f $(OBJS)

fclean	:
	make clean
	rm -f $(NAME)

re		:
	make fclean
	make all

.PHONY	: all clean fclean re