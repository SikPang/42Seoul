# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/01/24 16:12:07 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRCS	= main.c \
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
CFLAGS	= -lmlx -framework OpenGL -framework AppKit 
# -Wall -Werror -Wextra
# -lmlx -framework OpenGL -framework AppKit 
all		: $(NAME)

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