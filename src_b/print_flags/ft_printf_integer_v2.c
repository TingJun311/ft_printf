/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_v2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:51:11 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/07 15:55:26 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_integer_combination_5(char *str, int *len, int temp, t_format f)
{
	int	i;

	i = -1;
	(void)str;
	(void)temp;
	while (++i < (int)f.front)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}
