/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:32:42 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/02 18:38:22 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define HEXUP "0123456789ABCEDF"
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
	flag	front;
	flag	back;
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

void	check_precision(flag *f, flag *b, char *str);
#endif
