/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:27:40 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/01 16:28:09 by ctingjun         ###   ########.fr       */
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
