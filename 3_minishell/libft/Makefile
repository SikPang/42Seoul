# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 20:55:16 by sokwon            #+#    #+#              #
#    Updated: 2023/03/02 14:24:04 by kwsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SHELL = /bin/sh
UNAME	:= $(shell uname)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ifeq ($(UNAME), Linux)
 ARFLAGS		:= -Ucrus
else
 ARFLAGS		:= -crus
endif

SRCS_MDTRY	:= ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_strjoin_free.c \
				ft_strcmp.c \
				ft_error.c \
				ft_split.c \
				ft_strncpy.c
SRCS_BONUS	:= ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c
OBJS_MDTRY	= $(SRCS_MDTRY:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

OBJS_IN_LIB	:= $(shell [ -e "$(NAME)" ] && ar -t $(NAME) | tr '\n' ' ')
OBJS_DEL	:= $(filter $(OBJS_BONUS), $(OBJS_IN_LIB))
.BONUS		:= $(shell [ -e ".bonus" ] && echo ".bonus")
.PHONY	: all
all		: $(NAME)
ifneq (, $(OBJS_DEL))
	@echo ''
	$(AR) -ds $(NAME) $(OBJS_DEL)
endif
ifneq (, $(.BONUS))
	@echo ''
	rm -f .bonus
endif

.PHONY	: bonus
bonus	: .bonus

.bonus	:: $(NAME)
.bonus	:: $(OBJS_BONUS)
	@echo ''
	$(AR) $(ARFLAGS) $(NAME) $?
.bonus	:: $(NAME) $(OBJS_BONUS)
	@echo ''
	touch $@

$(NAME)	: $(OBJS_MDTRY)
	@echo ''
	$(AR) $(ARFLAGS) $@ $?

%.o	: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: clean
clean	:
	rm -f $(OBJS_MDTRY)
	rm -f $(OBJS_BONUS)
	rm -f .bonus

.PHONY	: fclean
fclean	: clean
	rm -f $(NAME)

.PHONY	: re
re		: fclean
	$(MAKE) all

.PHONY	: print
print	:
	@echo "members of $(NAME):"
	@ar -t $(NAME) | tr '\n' ' ' | sed 's/.$$/\n/'
