# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 16:16:11 by ctingjun          #+#    #+#              #
#    Updated: 2022/10/27 15:15:23 by ctingjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
INCLU = libft/
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_v2.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft.a $(OBJS)
	ar -rcs $(NAME) $(OBJS)

libft.a: $(INCLU)
	$(MAKE) all -C ./libft
	cp libft/libft.a $(NAME)

norm: $(SRC) ft_printf.h
	norminette $(SRC) ft_printf.h -R CheckForbiddenSourceHeader

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
