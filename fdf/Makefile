# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/02/01 14:17:04 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
MANDATORY	= .man
BONUS		= .bonus

SRCS_DIR	= ./Mandatory/
B_SRCS_DIR	= ./Bonus/
MLX_DIR		= ./mlx_mms

SRCS_FILE	= main.c \
			event.c \
			./draw/color.c \
			./draw/bresenham.c \
			./draw/draw.c \
			./data_structure/list.c \
			./data_structure/llist.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./utility/error_exit.c \
			./utility/ft_split.c \
			./utility/ft_atoh.c \
			./utility/ft_atoi.c \
			./utility/ft_calloc.c
B_SRCS_FILE	= main_bonus.c \
			event_bonus.c \
			./draw/color_bonus.c \
			./draw/bresenham_bonus.c \
			./draw/draw_bonus.c \
			./data_structure/list_bonus.c \
			./data_structure/llist_bonus.c \
			./get_next_line/get_next_line_bonus.c \
			./get_next_line/get_next_line_utils_bonus.c \
			./utility/error_exit_bonus.c \
			./utility/ft_split_bonus.c \
			./utility/ft_atoh_bonus.c \
			./utility/ft_atoi_bonus.c \
			./utility/ft_calloc_bonus.c \
			event2_bonus.c \
			./draw/draw_str_bonus.c \
			./utility/ft_itoa_bonus.c

SRCS	= $(addprefix $(SRCS_DIR), $(SRCS_FILE))
B_SRCS	= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILE))

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra
GFLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all		: $(MANDATORY)
	@touch $(MANDATORY)
	@rm -f $(BONUS)

$(MANDATORY)	: $(OBJS)
	$(CC) $(CFLAGS) $(GFLAGS) -o $(NAME) $^

bonus	: $(BONUS)
	@touch $(BONUS)
	@rm -f $(MANDATORY)

$(BONUS)		: $(B_OBJS)
	$(CC) $(GFLAGS) -o $(NAME) $^

clean	:
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean	:
	make clean
	rm -f $(NAME)
	@rm -f $(BONUS)
	@rm -f $(MANDATORY)

re		:
	make fclean
	make all

.PHONY	: all clean fclean re