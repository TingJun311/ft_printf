/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:58:40 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/10 16:57:29 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_printf_bonus.h"
void	ft_handle_min_int(int num, int *length, t_format f)
{
	int k;
	int	len;

	k = -1;
	len = 10;
	(void)num;
	while (++k < (int)f.back - len)
	{
		ft_putchar_fd('0', 1);
		(*length)++;
	}
	ft_putstr_fd("2147483648", 1);
	*length += 10;
}

void	print_combinations_1(int *len, int num, char *str, t_format f)
{
	int	i;
	int	length;
	int	con;

	i = -1;
	length = count_num(num);
	con = my_atoi(str);
	if (*str == '0')
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			*len += 1;
			num = -num;
			con--;
		}
		if (num == -2147483648)
		{
			f.back = con;
			ft_handle_min_int(num, len, f);
			return ;
		}
		length = count_num(num);
		while (++i < con - length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		ft_putnbr_fd(num, 1);
		*len += length;
	}
	else
	{
		while (++i < con - length)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		ft_putnbr_fd(num, 1);
		*len += length;
	}
}


void	ft_putnbr_negative(t_format f, int num, int *len)
{
	int	i;
	int	length;

	num = -num;
	length = count_num(num);
	i = -1;
	while (++i < (int)f.back - length)
	{
		ft_putchar_fd('0', 1);
		(*len)++;
	}
	ft_putnbr_fd(num, 1);
	*len += length;
}

void	print_combinations_2_1(int *len, int num, char *str, t_format f)
{
	int	con;
	int	i;
	int	length;
	int	print_len;

	print_len = 0;
	con = my_atoi(str);
	i = -1;
	if (num == 0 && f.back == 0)
	{
		while (++i < con)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
	}
	else
	{
		length = 0;
		i = -1;
		length += count_num(num);
		if ((int)f.back <= length)
			print_len = con - length;
		else
			print_len = (con - f.back);
		if (num < 0)
			print_len--;
		if (num == -2147483648)
			print_len++;
		while (++i < print_len)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		i = -1;
		if (num < 0 && num != -2147483648)
		{
				ft_putchar_fd('-', 1);
				num = -num;
				i--;
		}
		while (++i < (int)f.back - length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		if (num != 0)
		{
			ft_putnbr_fd(num, 1);
			*len += length;
		}
		else
		{
			ft_putchar_fd('0', 1);
			*len += 1;
		}
	}
}

void	print_combinations_2(int *len, int num, char *str, t_format f)
{
	int	i;
	int length;
	int	con;

	(void)num;
	(void)str;
	i = -1;
	length = 0;
	if (*str == '0')
	{
		print_combinations_2_1(len, num, str, f);
		return ;
	}
	if ((num == 0 && f.back == 0))
	{
		con = my_atoi(str);
		while (++i < con)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		return ;
	}
	i = -1;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		(*len)++;
		length++;
	}
	if (num == -2147483648)
		ft_handle_min_int(num, len, f);
	else if (num < 0)
		ft_putnbr_negative(f, num, len);
	else
	{
		length += count_num(num);
		while (++i < (int)f.back - length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		ft_putnbr_fd(num, 1);
		*len += length;
	}
}

void	print_combinations_3(int *len, int temp, char *str, t_format f)
{
	int	i;
	int con;
	int	length;

	length = 0;
	con = my_atoi(str);
	if (f.back == 0 && temp == 0 && f.dot == 1)
	{
		i = -1;
		while (++i < con)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		return ;
	}
	if (temp < 0)
	{
		ft_putchar_fd('-', 1);
		(*len)++;
		temp = -temp;
		con--;
	}
	if (temp == -2147483648)
		ft_handle_min_int(temp, len, f);
	else
	{
		i = -1;
		length += count_num(temp);
		while (++i < (int)f.back - length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		ft_putnbr_fd(temp, 1);
		*len += length;
		while (i++ < (int)con - length)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
	}
}

void	print_combinations_4(int *len, int num, char *str, t_format f)
{
	int	length;

	(void)str;
	(void)f;
	length = count_num(num);
	if (num >= 0)
	{
		ft_putchar_fd(' ', 1);
		*len += 1;
	}
	ft_putnbr_fd(num, 1);
	*len += length;
}

void	print_combinations_5(int *len, int num)
{
	int	length;

	length = count_num(num);
	if (num >= 0)
	{
		ft_putchar_fd('+', 1);
		*len += 1;
		ft_putnbr_fd(num, 1);
		*len += length;
	}
	else
	{
		ft_putnbr_fd(num, 1);
		*len += length;
	}
}

void	print_integer(t_format f, char *str, int *len, va_list ptr)
{
	int temp;

	(void)str;
	(void)len;
	temp = va_arg(ptr, int);
	check_precision(&(f.front), &(f.back), str);
	if ((f.num == 1 && f.sub == 0 && f.dot == 0 && f.add == 0) ||
			(f.zero == 1 && f.dot == 0 && f.sub == 0))
		print_combinations_1(len, temp, str, f);
	else if (f.dot == 1 && f.sub == 0)
		print_combinations_2(len, temp, str, f);
	else if ((f.num == 1 && f.dot == 1) || f.sub == 1)
		print_combinations_3(len, temp, str, f);
	else if (f.space == 1)
		print_combinations_4(len, temp, str, f);
	else if (f.add == 1)
		print_combinations_5(len, temp);
}
