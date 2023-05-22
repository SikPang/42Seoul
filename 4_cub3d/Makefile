# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:51:35 by kwsong            #+#    #+#              #
#    Updated: 2023/05/19 13:37:09 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
BONUS		= cub3D_bonus

SRCS_DIR	= ./Mandatory/srcs/
INC_DIR		= ./Mandatory/includes/

B_SRCS_DIR	= ./Bonus/srcs/
B_INC_DIR	= ./Bonus/includes/

MLX_DIR		= ./mlx/
MLX			= libmlx.a

FT_DIR		= ./libft/
FT			= libft.a

SRCS_FILE	= main.c \
			info.c \
			event.c \
			move.c \
			frame.c \
			error_handler.c \
			ft_math.c \
			draw/sprite.c \
			draw/canvas.c \
			draw/draw.c \
			draw/raycasting.c \
			draw/minimap.c \
			draw/texture.c \
			parsing/parsing1.c \
			parsing/parsing2.c \
			parsing/parsing3.c \
			parsing/parsing4.c \
			data_structure/stack.c \
			data_structure/list1.c \
			data_structure/list2.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
B_SRCS_FILE	= main_bonus.c \
			info_bonus.c \
			event_bonus.c \
			move_bonus.c \
			frame_bonus.c \
			error_handler_bonus.c \
			ft_math_bonus.c \
			draw/sprite_bonus.c \
			draw/canvas_bonus.c \
			draw/draw_bonus.c \
			draw/raycasting_bonus.c \
			draw/minimap_bonus.c \
			draw/texture_bonus.c \
			parsing/parsing1_bonus.c \
			parsing/parsing2_bonus.c \
			parsing/parsing3_bonus.c \
			parsing/parsing4_bonus.c \
			data_structure/stack_bonus.c \
			data_structure/list1_bonus.c \
			data_structure/list2_bonus.c \
			get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c

SRCS	= $(addprefix $(SRCS_DIR), $(SRCS_FILE))
B_SRCS	= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILE))

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra
GFLAGS	= $(MLX) -framework OpenGL -framework AppKit -lm

all		: $(NAME)

$(NAME)	: $(OBJS)
	make -C $(MLX_DIR)
	make -C $(FT_DIR)
	$(CC) $(CFLAGS) $(GFLAGS) $(FT) -o $(NAME) $^ -I$(FT_DIR) -I$(MLX_DIR) -I$(INC_DIR)

bonus	: $(BONUS)

$(BONUS)	: $(B_OBJS)
	make -C $(MLX_DIR)
	make -C $(FT_DIR)
	$(CC) $(CFLAGS) $(GFLAGS) $(FT) -o $(BONUS) $^ -I$(FT_DIR) -I$(MLX_DIR) -I$(B_INC_DIR)

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(FT_DIR) -I$(MLX_DIR) -I$(INC_DIR) -I$(B_INC_DIR)

clean	:
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean	:
	make clean
	make clean -C $(FT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(FT)
	rm -f $(NAME)
	rm -f $(MLX)
	rm -f $(BONUS)

re		:
	make fclean
	make all

.PHONY	: all clean fclean re bonus