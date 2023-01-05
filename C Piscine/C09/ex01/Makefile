NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= -rc

INC		= ./includes/
SRCS	= ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY : all clean fclean re
