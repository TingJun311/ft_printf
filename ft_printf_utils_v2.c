/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:32:06 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/27 14:28:55 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_printf_hex_p(unsigned long long int num, int *len)
{
	char			*base_down;

	base_down = "0123456789abcdef";
	if (num < 0)
		num = -num;
	if (num >= 16)
	{
		ft_printf_hex_p(num / 16, len);
		ft_printf_hex_p(num % 16, len);
	}
	else
	{
		ft_putchar_fd(base_down[num % 16], 1);
		*len += 1;
	}
}
