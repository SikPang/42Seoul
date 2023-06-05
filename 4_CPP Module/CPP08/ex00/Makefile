# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:36:16 by kwsong            #+#    #+#              #
#    Updated: 2023/06/05 21:39:25 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= easyfind

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 #-fsanitize=address

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $<

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