/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:35:22 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/27 18:08:30 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_conversions_tail(char c, va_list ptr, int *len)
{
	int				k;
	unsigned int	l;

	if (c == 'd' || c == 'i')
	{
		k = va_arg(ptr, int);
		*len += count_num(k);
		ft_putnbr_int(k);
	}
	else if (c == 'u')
	{
		l = va_arg(ptr, unsigned int);
		*len += count_unsigned(l);
		ft_putunsigned_int(l);
	}
	else if (c == 'x')
		ft_print_hex(va_arg(ptr, unsigned int), 'x', len);
	else if (c == 'X')
		ft_print_hex(va_arg(ptr, unsigned int), 'X', len);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		*len += 1;
	}
}

static int	ft_printf_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

static void	handle_conversions_head(char c, va_list ptr, int *len)
{
	char	*temp;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(ptr, int), 1);
		*len += 1;
	}
	else if (c == 's')
	{
		temp = va_arg(ptr, char *);
		if (temp == NULL)
			*len += ft_printf_null();
		else
		{
			*len += ft_strlen(temp);
			ft_putstr_fd(temp, 1);
		}
	}
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		*len += 2;
		ft_printf_hex_p(va_arg(ptr, unsigned long long int), len);
	}
	handle_conversions_tail(c, ptr, &(*len));
}

int	ft_printf(const	char *str, ...)
{
	va_list	ptr;
	size_t	i;
	int		total_length;

	i = -1;
	total_length = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			handle_conversions_head(str[i], ptr, &total_length);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			total_length++;
		}
	}
	va_end(ptr);
	return (total_length);
}

//#include <limits.h>
//int	main(void)
//{
//	int		length;
//
//	length = ft_printf("D: %x\n", -1);
//	printf("%#X", -10);
//	return (0);
//}
