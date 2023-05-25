# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:36:16 by kwsong            #+#    #+#              #
#    Updated: 2023/05/25 21:38:48 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= dynamic

SRCS	= main.cpp \
		Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp
OBJS	= $(SRCS:.cpp=.o)

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $<

clean	:
	rm -f $(OBJS)

fclean	:
	make clean
	rm -f $(NAME)

re		:
	make fclean
	make all

.PHONY	: all clean fclean re