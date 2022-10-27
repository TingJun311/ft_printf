/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:27:13 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/11 11:13:28 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	i;
	size_t	k;

	i = (char)c;
	k = 0;
	while (s[k])
	{
		if (s[k] == i)
			return ((char *)s + k);
		k++;
	}
	if (s[k] == i)
		return ((char *)s + k);
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	char str[50] = "This is a \0 string.";
//	char str1[50] = "This is a \0 string.";
//	char *r = ft_strchr(str, 90);
//	char *g = strchr(str1, 90);
//
//	printf("mine: %s\n %p\n", r, r);
//	printf("std: %s\n %p\n", g, g);
//	printf("Mine: %d\n", r == str + strlen(str));
//	printf("Std: %d\n", g == str1 + strlen(str1));
//	return (0);
//}
