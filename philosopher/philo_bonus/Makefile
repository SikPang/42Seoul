# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/04/04 22:21:00 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo_bonus

SRCS_FILE	= main \
			info \
			philosopher \
			philosopher_observe \
			time/ks_time \
			utility/ft_atoi \
			utility/ft_itoa \
			utility/ft_memcpy \
			utility/ft_strlen \
			utility/ft_strjoin \
			utility/error_exit

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