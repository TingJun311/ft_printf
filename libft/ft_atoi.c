/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:32:44 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/17 10:22:52 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	con;

	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	con = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		con = (con * 10) + (*nptr - 48);
		nptr++;
	}
	return (con * neg);
}

//#include <stdio.h>
//int	main(void)
//{
//	const char str[50] = "-99999999999999999999999999";
//	printf("Std: %d\n", atoi(str));
//	printf("Mine: %d\n", ft_atoi(str));
//	return (0);
//}
