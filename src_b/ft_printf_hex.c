/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:18:21 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/01 13:21:36 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_hex(unsigned int str, char c, int *len)
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
		if (c == 'p' || c == 'x')
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
