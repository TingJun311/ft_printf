/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:13:49 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 15:02:24 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	l;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	else if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	l = 0;
	while (l < len)
	{
		ptr[l] = s[start];
		start++;
		l++;
	}
	ptr[l] = '\0';
	return (ptr);
}

//int	main(void)
//{
//	char	str[50] = "trttt";
//	char	*r = ft_substr(str, 1, 1);
//	printf("Mine: %s\n", r);
//	return (0);
//}
