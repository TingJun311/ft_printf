/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:15:23 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/05 14:31:54 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s) = (unsigned char)c;
		s++;
		i++;
	}
	return (s - i);
}

//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	char str[50] = "This is a testing for the function";
//	printf("%s\n", memset(str + 13, '/', 5));
//	printf("%s\n", ft_memset(str + 13, '/', 5));
//	return (0);
//}
