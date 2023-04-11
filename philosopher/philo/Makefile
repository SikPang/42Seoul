# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/04/11 19:43:27 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS_FILE	= main \
			info \
			philosopher \
			philosopher_observe \
			mutex/access_mutex \
			mutex/access_mutex2 \
			time/time \
			utility/ft_atoi \
			utility/error_exit

SRCS	= $(addsuffix .c, $(SRCS_FILE))

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -fsanitize=thread

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