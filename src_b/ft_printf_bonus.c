/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:32:14 by ctingjun          #+#    #+#             */
/*   Updated: 2022/11/02 19:45:25 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static void	displayMan2(char c, int *len, va_list ptr)
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

static	void	displayMan(char c, int	*len, va_list ptr)
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
	displayMan2(c, len, ptr);
}


static	t_format	check_format(t_format f, char	*str, int	 *len, va_list ptr)
{
		int	i;

		i = -1;
		while (str[++i] && !is_conversions(str[i]))
		{
			if (str[i] == '+')
				f.add = 1;
			else if (str[i] == '-')
				f.sub = 1;
			else if (str[i] == ' ')
				f.space = 1;
			else if (str[i] == '.')
				f.dot = 1;
			else if (str[i] == '0')
				f.zero = 1;
			else if (str[i] == '#')
				f.hash = 1;
			else if (str[i] >= '1' && str[i] <= '9')
				f.num = 1;
		}
		f.current_con = str[i];
		print_out(f, str, len, ptr);
		return (f);
}

static	void	handle_conversions_1(char *str, int *len, va_list ptr)
{
	t_format	f;

	f = init_flags();
	if (*str && is_conversions(*str))
		displayMan(*str, len, ptr);
	else
		f = check_format(f, str, len, ptr);
}
int	ft_printf(const char *str, ...)
{
	flag			i;
	int				total_length;
	va_list		ptr;

	i = 0;
	total_length = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			handle_conversions_1((char *)(str + i), &total_length, ptr);
			while (str[i] && !is_conversions(str[i]))
				i++;
			i++;
		}
		else
		{
			ft_putchar_fd(str[i++], 1);
			total_length++;
		}
	}
	va_end(ptr);
	return (total_length);
}

int	main(void)
{
	void	*ptr;

	ptr = NULL;
	int l = ft_printf("%-20.20sb", NULL);
	printf("\nLength: %d\n", l);
	l = printf("%-20.20sb", NULL);
	printf("\nLength: %d", l);
	return (0);
}
