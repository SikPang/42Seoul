# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:36:16 by kwsong            #+#    #+#              #
#    Updated: 2023/06/09 16:33:58 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe

SRCS	= main.cpp \
		PmergeMe.cpp
OBJS	= $(SRCS:.cpp=.o)

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address

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