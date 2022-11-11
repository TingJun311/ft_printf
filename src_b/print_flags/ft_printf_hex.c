/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:54:52 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/11 20:07:41 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_print_hex_x(unsigned int str, char c, int *len)
{
	if (str < 0)
		str = -str;
	if (str >= 16)
	{
		ft_print_hex(str / 16, c, len);
		ft_print_hex(str % 16, c, len);
	}
	else
	{
		if (c == 'x')
		{
			ft_putchar_fd(HEXDOWN[str % 16], 1);
			*len += 1;
		}
		else if (c == 'X')
		{
			ft_putchar_fd(HEXUP[str % 16], 1);
			*len += 1;
		}
	}
}

void	print_combinations_hex_1(t_format f, char *str, int *len, unsigned int val)
{
	int length;
	int	i;
	int con;

	(void)f;
	(void)str;
	i = -1;
	con = my_atoi(str);
	length = 0;
	count_hex_p(val, &length);
	while (++i < con - length)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
	ft_print_hex_x(val, f.current_con, len);
}

void	print_combinations_hex_4_1(t_format f, char *str, int *len, unsigned int val);

void	print_combinations_hex_2(t_format f, char *str, int *len, unsigned int val)
{
	int	i;
	int length;

	i = -1;
	length = 0;
	if (*str != '.')
		print_combinations_hex_4_1(f, str, len, val);
	if (*str == '.')
	{
		count_hex_p(val, &length);
		while (++i < (int)f.back - length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		if (val == 0 && f.back == 0)
			return ;
		ft_print_hex_x(val, f.current_con, len);
	}
}

void	print_combinations_hex_3_1(t_format f, char *str, int *len, unsigned int val)
{
	int	i;
	int print_len;
	int	length;

	(void)str;
	i = -1;
	length = 0;
	count_hex_p(val, &length);
	if ((int)f.back <= length)
		print_len = (int)f.front - length;
	else
		print_len = (int)f.front - (int)f.back;
	while (++i < (int)f.back - length)
	{
		ft_putchar_fd('0', 1);
		(*len)++;
	}
	if (val == 0 && f.back == 0)
	{
		if (f.front == 0)
			return ;
		print_len++;
	}
	else
		ft_print_hex_x(val, f.current_con, len);
	i = -1;
	while (++i < print_len)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}

void	print_combinations_hex_3(t_format f, char *str, int *len, unsigned int val)
{
	int	i;
	int	con;
	int	length;

	con = my_atoi(str);
	i = -1;
	length = 0;
	count_hex_p(val, &length);
	if (*str == '-' && f.dot == 0)
	{
		ft_print_hex_x(val, f.current_con, len);
		while (++i < con - length)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
	}
	else if (*str == '-' && f.dot == 1)
		print_combinations_hex_3_1(f, str, len, val);
}

void	print_combinations_hex_4_1(t_format f, char *str, int *len, unsigned int val)
{
	int i;
	int	con;
	int	length;

	i = -1;
	length = 0;
	con = my_atoi(str);
	count_hex_p(val, &length);
	if (f.front > f.back)
	{
		if (f.back >= length)
		{
			while (++i < f.front - f.back)
			{
				ft_putchar_fd(' ', 1);
				(*len)++;
			}
		}
		else
		{
			while (++i < f.front - length)
			{
				ft_putchar_fd(' ', 1);
				(*len)++;
			}
		}
	}
	i = -1;
		if (f.back >= length)
		{
			while (++i < f.back - length)
			{
				ft_putchar_fd('0', 1);
				(*len)++;
			}
		}
	if (val == 0 && (f.back == -1 || f.back == 0))
	{
		ft_putchar_fd(' ', 1);
		*len += 1;
	}
	else
		ft_print_hex_x(val, f.current_con, len);
}

void	print_combinations_hex_4(t_format f, char *str, int *len, unsigned int val)
{
	int	i;
	int	length;
	int	con;

	i = -1;
	length = 0;
	con = my_atoi(str);
	count_hex_p(val, &length);
	if (f.dot == 0)
	{
		i = -1;
		while (++i < con - length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		ft_print_hex_x(val, f.current_con, len);
	}
	else
		print_combinations_hex_4_1(f, str, len, val);
}

void	print_combinations_hex_5(t_format f, int *len, unsigned int val)
{
	if (val == 0)
	{
		ft_putchar_fd('0', 1);
		*len += 1;
		return ;
	}
	if (f.current_con == 'x')
		print_hex_front(len);
	else
		print_hex_front_2(len);
	ft_print_hex_x(val, f.current_con, len);
}

void	print_hex(t_format f, char *str, int *len, va_list ptr)
{
	unsigned int	val;

	val = va_arg(ptr, unsigned int);

	check_precision(&(f.front), &(f.back), str);
	if (f.num == 1 && f.dot == 0 && f.space == 0 && f.sub == 0 && f.add == 0 && *str != '0')
		print_combinations_hex_1(f, str, len, val);
	else if (f.dot == 1 && f.sub == 0 && *str != '0')
		print_combinations_hex_2(f, str, len, val);
	else if ((f.dot == 1 || f.sub == 1) && *str != '0')
		print_combinations_hex_3(f, str, len, val);
	else if (*str == '0')
	{
		check_precision_2(&(f.front), &(f.back), str);
		print_combinations_hex_4(f, str, len, val);
	}
	else if (f.hash)
		print_combinations_hex_5(f, len, val);
}
