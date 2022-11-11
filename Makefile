# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 16:16:11 by ctingjun          #+#    #+#              #
#    Updated: 2022/11/11 14:56:32 by ctingjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
INCLU = libft/
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_v2.c

BONUS_PATH = src_b/
BONUS = src_b/ft_printf_bonus.c src_b/ft_printf_hex.c \
				src_b/ft_printf_handle_conversions.c  src_b/ft_printf_hex_p.c  \
				src_b/ft_printf_hex_p.c src_b/ft_printf_utils_bonus.c src_b/ft_putnbr_int.c \
				src_b/ft_putunsigned_int.c src_b/print_flags/ft_printf_char.c \
				src_b/print_flags/ft_printf_string.c src_b/ft_printf_utils_v2_bonus.c \
				src_b/print_flags/ft_printf_string_v2.c src_b/print_flags/ft_printf_address.c \
				src_b/print_flags/ft_printf_integer.c src_b/print_flags/ft_printf_integer_v2.c \
				src_b/print_flags/ft_printf_u_integer.c src_b/print_flags/ft_printf_hex.c

OBJS = $(SRC:.c=.o)
B_OBJS = $(BONUS:.c=.o)

all: bonus

$(NAME): libft.a $(OBJS)
	ar -rcs $(NAME) $(OBJS)

libft.a: $(INCLU)
	$(MAKE) all -C ./libft
	cp libft/libft.a $(NAME)

norm: $(SRC) ft_printf.h
	norminette $(SRC) ft_printf.h -R CheckForbiddenSourceHeader

bonus: $(B_OBJS) libft.a
	ar -rcs $(NAME) $(B_OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
