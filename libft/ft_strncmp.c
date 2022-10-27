/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:22:56 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/12 12:06:37 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

//int	main(void)
//{
//	char s1[50] = "1111111112";
//	char s2[50] = "1111111112";
//	int r = strncmp(s1, s2, 20);
//	int k = ft_strncmp(s1, s2, 20);
//
//	printf("std: %d\n", r);
//	printf("Mine: %d\n", k);
//	return (0);
//}
