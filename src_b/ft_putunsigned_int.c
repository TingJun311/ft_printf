/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:33:20 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/01 16:35:00 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putunsigned_int(unsigned int num)
{
	unsigned int	k;

	k = 0;
	if (num < 0)
	{
		num = -num;
		k = 4294967295 - num + 1;
	}
	if (num > 9)
	{
		ft_putunsigned_int(num / 10);
		ft_putunsigned_int(num % 10);
	}
	else
		ft_putchar_fd(num + 48, 1);
}
