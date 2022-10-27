/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:35:42 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 14:01:50 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

//#include <stdio.h>
//int	main(int ac, char **av)
//{
//	(void)ac;
//	(void)av;
//	printf("%d\n", ft_isalpha(av[1][0]));
//	return (0);
//}
