/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:26:47 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 15:09:51 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	c;
	char	*t_dest;	
	char	*t_src;

	if (!dest && !src)
		return (NULL);
	t_dest = (char *)dest;
	t_src = (char *)src;
	c = 0;
	while (c < n)
	{
		t_dest[c] = t_src[c];
		c++;
	}
	return (dest);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	//char src[50] = "abcdefghijklm";
//	char dest[50] = "123456789";
//	char *result = memcpy(dest, dest, 7);
//
//	printf("Result: %s\n", result);
//	//printf("Source: %s\n", src);
//	return (0);
//}
