/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:24:44 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 14:42:46 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = (char *)malloc(len + 1 * sizeof(char));
	len = 0;
	if (ptr == NULL)
		return (NULL);
	while (s[len])
	{
		ptr[len] = s[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}

//int	main(void)
//{
//	char str[] = "b";
//	char str1[] = "b";
//	char *r = ft_strdup(str);
//	char *z = strdup(str1);
//	printf("Mine: %s\n", r);
//	printf("Std: %s", z);
//	return (0);
//}
