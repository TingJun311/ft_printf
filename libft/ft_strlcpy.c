/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:26:18 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/11 12:01:33 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	c;

	c = 0;
	if (size > 0)
	{
		while (c < size - 1 && src[c])
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
		c = 0;
	}
	while (src[c])
		c++;
	return (c);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	char dest[] = "DdDdDdDdD";
//	char src[] = "WwWwWwW";
//	size_t c = ft_strlcpy(dest, src, -1);
//	printf("Std: %s\n", dest);
//	printf("Std: %s\n", src);
//	printf("Length: %zu\n", c);
//	return (0);
//}
