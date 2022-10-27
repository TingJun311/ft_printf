/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:31:54 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 14:42:13 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*res;
	size_t	i;
	char	*con;

	if (elsize != 0 && (nelem >= (SIZE_MAX / elsize)))
		return (NULL);
	res = (char *)malloc(nelem * elsize);
	if (res == NULL)
		return (NULL);
	i = 0;
	con = (char *)res;
	while (i < nelem * elsize)
	{
		res[i] = 0;
		i++;
	}
	res[i] = '\0';
	return (res);
}

//#include <stdio.h>
//int	main(void)
//{
//	//char *r = ft_calloc(2, 2);
//	char *k = ft_calloc(SIZE_MAX, SIZE_MAX);
//	//for (int i = 0; i < 2; i++)
//	//	printf("%d\n", r[i]);
//	//free(r);
//	for (size_t j = 0; j < 10000; j++)
//		printf("%d\n", k[j]);
//	free(k);
//	return (0);
//}
