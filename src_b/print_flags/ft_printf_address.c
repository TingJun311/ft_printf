/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:28:01 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/04 15:49:03 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_printf_bonus.h"


void	count_hex_p(unsigned long long int num, int *len)
{
	if (num < 0)
		num = -num;
	if (num >= 16)
	{
		count_hex_p(num / 16, len);
		count_hex_p(num % 16, len);
	}
	else
		(*len)++;
}

void	print_address_combinations_1(char *str, int *len, unsigned long long int temp)
{
	int	length;
	int num;
	int	i;

	num = my_atoi(str);
	length = 0;
	count_hex_p(temp, &length);
	if (num <= length + 2)
	{
		print_hex_front(len);
		ft_printf_hex_p(temp, len);
	}
	else
	{
		i = -1;
		while (++i < num - (length + 2))
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		print_hex_front(len);
		ft_printf_hex_p(temp, len);
	}
}

void	print_address_combinations_2(char *str, int *len, unsigned long long int temp)
{
	int	length;
	int	i;
	int	num;

	length = 0;
	count_hex_p(temp, &length);
	if (*str == '-')
		str++;
	num = my_atoi(str);
	if (num <= length + 2)
	{
		print_hex_front(len);
		ft_printf_hex_p(temp, len);
	}
	else
	{
		i = -1;
		print_hex_front(len);
		ft_printf_hex_p(temp, len);
		while (++i < num - (length + 2))
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
	}
}

void	print_address(t_format f, char *str, int *len, va_list ptr)
{
	unsigned long long int	temp;

	temp = va_arg(ptr, unsigned long long int);
	(void)f;
	if (*str >= '0' && *str <= '9')
		print_address_combinations_1(str, len, temp);
	else if (*str == '-')
		print_address_combinations_2(str, len, temp);
}
