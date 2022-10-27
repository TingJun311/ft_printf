/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:33:17 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 15:09:06 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && !src)
		return (NULL);
	if (src <= dest)
	{
		while (n > 0)
		{
			*(char *)(dest + n - 1) = *(char *)(src + n - 1);
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	char dest[20] = "0123456789";
//	char *result = ft_memmove(&dest[1], dest, 2);
//	printf("%s\n", result);
//	return (0);
//}
