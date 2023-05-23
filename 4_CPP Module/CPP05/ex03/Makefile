# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:36:16 by kwsong            #+#    #+#              #
#    Updated: 2023/05/23 21:10:14 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat

SRCS	= main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp
OBJS	= $(SRCS:.cpp=.o)

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

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
	rm -f *_shrubbery

re		:
	make fclean
	make all

.PHONY	: all clean fclean re