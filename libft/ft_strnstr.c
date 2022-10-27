/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:18:56 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 14:07:08 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(little);
	if (big == NULL && len == 0)
		return (NULL);
	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
			j++;
		if (j == k)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	const char big[50] = "aaabcabcd";
//	const char little[50] = "cd";
//	char *res = strstr(big, little);
//	char *r = ft_strnstr(big, little, 8);
//
//	printf("Std: %s\n", res);
//	printf("Adress: %p\n", big);
//	printf("Mine: %s\n address: %p", r, r);
//	return (0);
//}
