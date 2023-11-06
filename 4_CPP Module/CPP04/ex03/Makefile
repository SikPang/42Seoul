# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:36:16 by kwsong            #+#    #+#              #
#    Updated: 2023/11/06 22:13:35 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= interface

SRCS	= main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		Inventory.cpp \
		MateriaSource.cpp
OBJS	= $(SRCS:.cpp=.o)

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $<

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

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