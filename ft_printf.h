/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:28:30 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/27 15:14:49 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);

void	ft_print_hex(unsigned int str, char c, int *len);

size_t	ft_putunsigned_int(unsigned int num);

int		count_num(int num);

int		count_unsigned(unsigned int num);

void	ft_putnbr_int(int num);

void	ft_printf_hex_p(unsigned long long int num, int *len);

#endif
