/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:32:42 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/11 19:46:01 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define HEXUP "0123456789ABCDEF"
# define HEXDOWN "0123456789abcdef"
# define CONVERSIONS "cspdiuxX%"
# define FLAGS "+- .#0"

typedef unsigned int flag;

typedef struct flags
{
	flag	add;
	flag	sub;
	flag	space;
	flag	dot;
	flag	hash;
	flag	num;
	flag	zero;
	int		front;
	int		back;
	char	current_con;
}	t_format;

int		ft_printf(const char *str, ...);

t_format init_flags(void);

int		is_conversions(char c);

int		ft_printf_null(void);

void	ft_print_hex(unsigned int str, char c, int *len);

void	ft_printf_hex_p(unsigned long long int num, int *len);

int		count_num(int num);

void	ft_putnbr_int(int num);

int		count_unsigned(unsigned int num);

void	ft_putunsigned_int(unsigned int num);

void	print_out(t_format f, char *str, int *len, va_list ptr);

void	print_char(t_format f, char *str, int *len, va_list ptr);

int		my_atoi(char *nptr);

void	print_string(t_format f, char *str, int *len, va_list ptr);

void	check_precision(int *f, int *b, char *str);

void	print_string_combination_5(char *str, int *len, char *temp);

void	print_string_combination_6(char *str, int *len);

void	print_address(t_format f, char *str, int *len, va_list ptr);

void	count_hex_p(unsigned long long int num, int *len);

void	print_hex_front(int *len);

void	print_integer(t_format f, char *str, int *len, va_list ptr);

void	ft_putnbr_u_i_d(int temp, t_format f, int *len);

void	ft_putnbr_positive(int num, t_format f, int *len);

void	print_integer_combination_5(char *str, int *len, int temp, t_format f);

void	print_u_integer(t_format f, char *str, int *len, va_list ptr);

void	print_hex(t_format f, char *str, int *len, va_list ptr);

void	check_precision_2(int *f, int *b, char *str);

void	print_hex_front_2(int *len);
#endif
