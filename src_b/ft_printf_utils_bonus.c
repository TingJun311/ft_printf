/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:20:23 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/02 16:54:14 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	init_flags(void)
{
	t_format	new_flags;

	new_flags.add = 0;
	new_flags.sub = 0;
	new_flags.space = 0;
	new_flags.dot = 0;
	new_flags.hash = 0;
	new_flags.num = 0;
	new_flags.zero = 0;
	return (new_flags);
}

int	is_conversions(char	c)
{
	size_t	i;

	i = 0;
	while (CONVERSIONS[i])
	{
		if (CONVERSIONS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

int	count_num(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	count_unsigned(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	my_atoi(char *nptr)
{
	int	con;

	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
		nptr++;
	con = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		con = (con * 10) + (*nptr - 48);
		nptr++;
	}
	return (con);
}
