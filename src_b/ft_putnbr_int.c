/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:27:40 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/09 10:35:36 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_int(int num)
{
	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return ;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr_int(num / 10);
		ft_putnbr_int(num % 10);
	}
	else
		ft_putchar_fd(num + 48, 1);
}


void	ft_putnbr_neg(int num, t_format f, int *len, int *length)
{
	int	i;

	num = -num;
	ft_putchar_fd('-', 1);
	*len += 1;
	if ((int)f.back > *length)
	{
		i = -1;
		while (++i < (int)f.back - *length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		ft_putnbr_int(num);
		*len += *length;
	}
	else
	{
		ft_putnbr_int(num);
		*len += *length;
	}
}

void	ft_putnbr_positive(int num, t_format f, int *len)
{
	int length;
	int	i;

	length = count_unsigned(num);
	if ((int)f.back >= length)
	{
		i = -1;
		while (++i < (int)f.back - length)
		{
			ft_putchar_fd('0', 1);
			(*len)++;
		}
		ft_putnbr_int(num);
		*len += length;
		while (i < (int)f.front - length)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
			i++;
		}
	}
	else
	{
		ft_putnbr_int(num);
		*len += length;
	}
}
