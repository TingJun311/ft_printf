/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_v2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:36:54 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/11 19:08:24 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_precision(int *f, int *b, char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] && !is_conversions(str[i]))
	{
		if (str[i] == '.')
		{
			c = i;
			if (str[c - 1] >= '0' && str[c - 1] <= '9')
				*f = my_atoi(str);
			if (str[c + 1] >= '0' && str[c + 1] <= '9')
			{
				c++;
				*b = my_atoi(str + c);
			}
		}
		i++;
	}
}

void	print_hex_front(int *len)
{
	*len += 2;
	ft_putstr_fd("0x", 1);
}

void	print_hex_front_2(int *len)
{
	*len += 2;
	ft_putstr_fd("0X", 1);
}

void	check_precision_2(int *f, int *b, char *str)
{
	int i;

	i = -1;
	*f = -1;
	*b = -1;
	while (str[++i] && !is_conversions(str[i]))
	{
		if (str[i] == '.')
		{
			if (str[i - 1] >= '0' && str[i - 1] <= '9')
				*f = my_atoi(str);
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				*b = my_atoi(str + i + 1);
		}
	}
}
