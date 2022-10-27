/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:54:09 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 18:42:01 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_checkfront(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trimback(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*error_handle(void)
{
	char	*ptr;

	ptr = malloc(1);
	ptr[0] = 0;
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	index;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_checkfront(set, s1[i]))
		i++;
	j = ft_strlen(s1 + i) - 1;
	if (i == ft_strlen(s1))
		return (error_handle());
	while (j + i > i && ft_trimback(s1[(j) + i], set))
		j--;
	ptr = (char *)malloc(sizeof(char) * (j + 2));
	if (ptr == NULL)
		return (NULL);
	index = j;
	j = 0;
	while (j < index + 1)
		ptr[j++] = s1[i++];
	ptr[j] = '\0';
	return (ptr);
}

//#include <stdio.h>
//int	main(void)
//{
//	char str[100] = "";
//	char set[50] = "123";
//	char *r = ft_strtrim(str, set);
//	if (!r)
//		printf("ok");
//	printf("Std: %s\n", r);
//	return (0);
//}
