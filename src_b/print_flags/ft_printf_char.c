/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:09:53 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/02 16:55:11 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_char_v2(char *str, int *len, va_list ptr)

{
	int num;
	int	i;

	i = -1;
	num = ft_atoi(str);
	while (++i < num - 1)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
	ft_putchar_fd(va_arg(ptr, int), 1);
	*len += 1;
}

void	print_char(t_format f, char *str, int *len, va_list ptr)
{
	int			i;
	int			num;

	i = -1;
	if (f.sub == 1 && f.num == 1)
	{
		num = my_atoi(str);
		ft_putchar_fd(va_arg(ptr, int), 1);
		*len += 1;
		while (++i < num - 1)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
	}
	else if (f.num == 1)
		print_char_v2(str, len, ptr);
	else if (f.sub == 1)
	{
		ft_putchar_fd(va_arg(ptr, int), 1);
		*len += 1;
	}
	else
		return ;
}
