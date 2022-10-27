/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:30:06 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 13:58:30 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*i;
	unsigned char	k;
	size_t			j;	

	j = 0;
	i = (unsigned char *)s;
	k = (unsigned char)c;
	while (j < n)
	{
		if (i[j] == k)
			return ((void *)i + j);
		j++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	const char str[50] = "This is a string.";
//	const char str1[50] = "This is a string.";
//   	char *ret;
//	char *r = ft_memchr(str1, 0, 1);
//   	ret = memchr(str, 0, 1);
//
//   	printf("Std: %s\n", ret);
//	printf("Mine: %s\n", r);
//
//   	return(0);
//}
