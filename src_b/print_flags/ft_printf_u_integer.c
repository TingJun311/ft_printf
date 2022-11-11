/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:06:56 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/11 14:52:38 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_u_combinations_2_1(unsigned int num, char *str, int *len, t_format f)
{
	 int	con;
	 int	length;
	 int	i;
	 int	print_len;

	 print_len = 0;
	 con = my_atoi(str);
	 length = count_unsigned(num);
	 i = -1;
	 if ((int)f.back <= count_unsigned(num))
	 	print_len += con - count_unsigned(num);
	 else
	 	print_len += (int)f.back - con;
	 while (++i < con - length)
	 {
	 	if (f.back == 0 && f.dot == 1)
	 		ft_putchar_fd(' ', 1);
	 	else if (f.dot == 1 && (int)f.back < length)
	 		ft_putchar_fd(' ', 1);
		else if (f.dot == 1 && (int)f.front > ((int)f.back))
			ft_putchar_fd(' ', 1);
	 	else
	 		ft_putchar_fd('0', 1);
	 	(*len)++;
	 }
	 i = -1;
	 if (f.back != 0 && (int)f.back > length)
	 {
	 	while (++i < print_len)
	 	{
	 		ft_putchar_fd('0', 1);
	 		(*len)++;
	 	}
	 }
	 if (num == 0 && f.dot == 1 && f.back == 0)
	 {
	 	ft_putchar_fd(' ', 1);
	 	*len += 1;
		}
	 else
	 {
	 	ft_putunsigned_int(num);
	 	*len += count_unsigned(num);
	 }
}

void	print_u_combinations_1(unsigned int num, char *str, int *len, t_format f)
{
	int	i;
	int	con;
	int	print_len;

	print_len = 0;
	con = my_atoi(str);
	i = -1;
	if (*str != '0')
	{
		while (++i < con - count_unsigned(num))
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		ft_putunsigned_int(num);
		*len += count_unsigned(num);
	}
	else
		print_u_combinations_2_1(num, str, len, f);
}

void	print_u_combinations_2(t_format f, unsigned int num, char *str, int *len)
{
	int	i;
	int	con;
	int	print_len;

	i = -1;
	print_len = 0;
	if (*str == '0')
	{
		print_u_combinations_1(num, str, len, f);
		return ;
	}
	if (num == 0 && f.back == 0 && *str != '-')
		return ;
	con = my_atoi(str);
	while (++i < (int)f.back - count_unsigned(num))
	{
		ft_putchar_fd('0', 1);
		(*len)++;
	}
	if (num == 0 && f.dot == 0 && *str == '-')
	{
		ft_putchar_fd('0', 1);
		*len += 1;
		print_len--;
	}
	if ((num != 0 || f.back != 0))
	{
		ft_putunsigned_int(num);
		*len += count_unsigned(num);
	}
	else
		print_len++;
	i = -1;
	if ((int)f.back <= count_unsigned(num))
		print_len += con - count_unsigned(num);
	else
		print_len += con - (int)f.back;
	while (++i < print_len)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}

void	print_u_integer(t_format f, char *str, int *len, va_list ptr)
{
	(void)f;
	(void)str;
	(void)len;
	(void)ptr;
	int	num;

	num = va_arg(ptr, unsigned int);
	check_precision(&(f.front), &(f.back), str);
	if (f.num == 1 && f.dot == 0 && f.space == 0 && f.sub == 0 && f.add == 0)
		print_u_combinations_1(num, str, len, f);
	else if ((f.dot == 1 && f.space == 0 && f.add == 0)|| f.sub == 1 || f.zero == 1)
		print_u_combinations_2(f, num, str, len);
}
