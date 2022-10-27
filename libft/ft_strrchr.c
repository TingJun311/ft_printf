/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:17:04 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/07 11:10:14 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	h;

	h = (char)c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == h)
			return ((char *)s + len);
		len--;
	}
	if (s[len] == h)
		return ((char *)s);
	return (NULL);
}

//int	main(void)
//{
//	char str[50] = "This is a string.";
//	char str1[50] = "This is a string.";
//	char *r = strrchr(str, 122);
//	char *k = ft_strrchr(str1, 122);
//
//
//	printf("Build in: %s\n", r);
//	printf("Mine: %s\n", k);
//	return (0);
//}
