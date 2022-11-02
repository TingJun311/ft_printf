/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:34:17 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/01 15:36:57 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printf_hex_p(unsigned long long int num, int *len)
{
	if (num < 0)
		num = -num;
	if (num >= 16)
	{
		ft_printf_hex_p(num / 16, len);
		ft_printf_hex_p(num % 16, len);
	}
	else
	{
		ft_putchar_fd(HEXDOWN[num % 16], 1);
		*len += 1;
	}
}
