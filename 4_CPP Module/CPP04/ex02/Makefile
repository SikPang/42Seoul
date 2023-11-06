# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:36:16 by kwsong            #+#    #+#              #
#    Updated: 2023/11/06 22:29:06 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= abstract

SRCS	= main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp
OBJS	= $(SRCS:.cpp=.o)

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $<

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 #-fsanitize=address

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