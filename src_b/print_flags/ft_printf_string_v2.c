/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_v2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:13:18 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/04 12:06:31 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_printf_bonus.h"

void	print_string_combination_5(char *str, int *len, char *temp)
{
	int num;
	int	i;

	num = my_atoi(str + 1);
	i = -1;
	while (++i < num && temp[i])
	{
		ft_putchar_fd(temp[i], 1);
		(*len)++;
	}
}

void	print_string_combination_6(char *str, int *len)
{
	int num;
	int	i;

	num = my_atoi(str);
	i = -1;
	while (++i < num)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}
