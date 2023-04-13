# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/04/13 21:29:17 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= micro

SRCS_FILE	= main \

SRCS	= $(addsuffix .c, $(SRCS_FILE))

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -fsanitize=address

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