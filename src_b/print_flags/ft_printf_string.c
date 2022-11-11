/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:57:13 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/11 19:47:29 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_string_combination_1(int *len, char *temp, t_format f)
{
		size_t	i;
		int			index;

		index = 0;
		i = ft_strlen(temp);
		if (f.back >= (int)i)
		{
			ft_putstr_fd(temp, 1);
			*len += i;
			index = i;
		}
		else
		{
			while (f.back < (int)i && f.back-- != 0)
			{
				ft_putchar_fd(temp[index++], 1);
				(*len)++;
			}
		}
	  while (index < f.front)
	  {
	  	ft_putchar_fd(' ', 1);
	  	(*len)++;
	  	index++;
	  }
}

void	print_string_combination_2(char *str, int *len, char *temp, t_format f)
{
	int			num;
	size_t	i;

	num = my_atoi(str);
	i = ft_strlen(temp);
	if (f.back >= (int)i)
	{
		*len += i;
		ft_putstr_fd(temp, 1);
	}
	else
	{
		num = -1;
		while (++num < (int)f.front - (int)f.back)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		num = -1;
		while (++num < (int)f.back && temp[num])
		{
			ft_putchar_fd(temp[num], 1);
			(*len)++;
		}
	}
}

void	print_string_combination_3(char *str, int *len, char *temp)
{
	size_t	i;
	int			num;
	int			j;

	if (*str == '0')
		str++;
	num = my_atoi(str);
	i = ft_strlen(temp);
	j = -1;
	while (++j < num - (int)i)
	{
		ft_putchar_fd('0', 1);
		(*len)++;
	}
	ft_putstr_fd(temp, 1);
	*len += i;
}

void	print_string_combination_4(char *str, int *len, char *temp)
{
	size_t	i;
	int			j;

	i = ft_strlen(temp);
	j = -1;
	if (*str != '-')
	{
		while (++j < my_atoi(str) - (int)i)
		{
			ft_putchar_fd(' ', 1);
			(*len)++;
		}
		ft_putstr_fd(temp, 1);
		*len += i;
	}
	else
	{
		j = -1;
		if ((int)ft_strlen(temp) > my_atoi(str + 1) && *str == '-')
		{
			ft_putstr_fd(temp, 1);
			*len += ft_strlen(temp);
		}
		else
		{
			while (++j < my_atoi(str) && temp[j])
			{
				ft_putchar_fd(temp[j], 1);
				(*len)++;
			}
			while (j++ < my_atoi(str))
			{
				ft_putchar_fd(' ', 1);
				(*len)++;
			}
		}
	}
}

void	print_string(t_format f, char *str, int *len, va_list ptr)
{
	char		*temp;

	temp = va_arg(ptr, char *);
	if (temp == NULL)
		temp = "(null)";
	check_precision(&(f.front), &(f.back), str);
	if (f.dot == 1 && f.sub == 1)
		print_string_combination_1(len, temp, f);
	else if (f.dot == 1 && f.num == 1 && *str != '.' && f.back != 0)
		print_string_combination_2(str, len, temp, f);
	else if (f.num == 1 && f.zero == 1 && *str == '0')
		print_string_combination_3(str, len, temp);
	else if (f.num == 1 && *str != '0' && f.dot == 0)
		print_string_combination_4(str, len, temp);
	else if ((f.zero == 1 && *str == '0') || (f.sub == 1 && is_conversions(str[1])))
	{
		*len +=  (int)ft_strlen(temp);
		ft_putstr_fd(temp, 1);
	}
	else if (*str == '.')
		print_string_combination_5(str, len, temp);
	else if (f.front != 0 && str[1] == '.')
		print_string_combination_6(str, len);
}
