/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:02:16 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 14:04:43 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	d;

	if (dst == NULL && size == 0)
		return (0);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != '\0' && c + 1 < size)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	char dest[50] = "12345";
//	char src[50] = "abcdefghijk";
//
//	size_t c = strlcat(dest, src, 7);
//	printf("Dest: %s\n", dest);
//	printf("Src: %s\n", src);
//	printf("Size: %zu", c);
//	return (0);
//}
