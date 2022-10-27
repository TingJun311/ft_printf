/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:28:47 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/07 12:06:21 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*k;
	size_t			j;

	i = (unsigned char *)s1;
	k = (unsigned char *)s2;
	j = 0;
	while (j < n)
	{
		if (i[j] != k[j])
			return (i[j] - k[j]);
		j++;
	}
	return (0);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
// 	const char str[50] = "YY\0tyu";
//	const char str1[50] = "YY\0abc";
//	int r = memcmp(str, str1, 30);
//	int result = ft_memcmp(str, str1, 30);
//
//	printf("Std: %d\n", r);
//	printf("Mine: %d\n", result);
//
//	return (0);
//}
