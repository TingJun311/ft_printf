/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:36 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/27 15:11:17 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int str, char c, int *len)
{
	char			*base_up;
	char			*base_down;

	base_up = "0123456789ABCDEF";
	base_down = "0123456789abcdef";
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
			ft_putchar_fd(base_down[str % 16], 1);
			*len += 1;
		}
		else if (c == 'X')
		{
			ft_putchar_fd(base_up[str % 16], 1);
			*len += 1;
		}
	}
}

size_t	ft_putunsigned_int(unsigned int num)
{
	size_t			i;
	unsigned int	k;

	i = 0;
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
	{
		ft_putchar_fd(num + 48, 1);
		i++;
	}
	return (i);
}

int	ft_strlenv2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
