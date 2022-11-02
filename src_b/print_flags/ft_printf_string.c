/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:57:13 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/02 19:44:48 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_string_combination_1(int *len, char *temp, t_format f)
{
		size_t	i;
		int			index;

		index = 0;
		i = ft_strlen(temp);
		if (f.back >= i)
		{
			ft_putstr_fd(temp, 1);
			*len += i;
			index = i;
		}
		else
		{
			while (f.back < i && f.back-- != 0)
			{
				ft_putchar_fd(temp[index++], 1);
				(*len)++;
			}
		}
		while ((flag)index < f.front)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
			index++;
		}
}

void	print_string_combination_2(char *str, int *len, char *temp)
{
	int			num;
	size_t	i;

	if (*str == '0')
		str++;
	num = my_atoi(str);
	i = ft_strlen(temp);
	while (num > (int)i)
	{
		ft_putchar_fd('0', 1);
		num--;
		(*len)++;
	}
	*len += i;
	ft_putstr_fd(temp, 1);
}

void	check_precision(flag *f, flag *b, char *str)
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

void	print_string(t_format f, char *str, int *len, va_list ptr)
{
	char		*temp;
	int			index;

	temp = va_arg(ptr, char *);
	if (temp == NULL)
		temp = "(null)";
	index = -1;
	check_precision(&(f.front), &(f.back), str);
	if (f.dot == 1 && f.back != 0 && f.front != 0 && f.sub == 1)
		print_string_combination_1(len, temp, f);
	else if (f.dot == 1 && f.sub == 1 )
		print_string_combination_2(str, len, temp);
}
