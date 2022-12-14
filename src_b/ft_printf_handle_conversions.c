/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_conversions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:21:29 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/11 14:53:54 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_out(t_format f, char *str, int *len, va_list ptr)
{
	(void)len;
	(void)str;
	if (f.current_con == 'c')
		print_char(f, str, len, ptr);
	else if (f.current_con == 's')
		print_string(f, str, len, ptr);
	else if (f.current_con == 'p')
		print_address(f, str, len, ptr);
	else if (f.current_con == 'i' || f.current_con == 'd')
		print_integer(f, str, len, ptr);
	else if (f.current_con == 'u')
		print_u_integer(f, str, len, ptr);
	else if (f.current_con == 'x' || f.current_con == 'X')
		print_hex(f, str, len, ptr);
}
