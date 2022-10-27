/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:58 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/12 11:39:19 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// This function its for counting the lenght before any char occur. ok?`
static	size_t	ft_count_len(const char *s, char i)
{
	size_t	k;

	k = 0;
	while (s[k] != i && s[k])
		k++;
	return (k);
}

// This funtions return a value on how many should the string split.
static	size_t	ft_len_outer(const char *s, char t)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] != t)
		{
			r++;
			while (s[i] && s[i] != t)
				i++;
		}
		else
			i++;
	}
	return (r);
}

// This function return a pointer of a substr
static	char	*inner_alloc(const char *s, size_t length)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	while (i < length)
	{
		ptr[i] = s[0];
		s++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	sub_length;

	if (s == NULL)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (ft_len_outer(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			sub_length = ft_count_len(s, c);
			ptr[i] = inner_alloc(s, sub_length);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	ptr[i] = 0;
	return (ptr);
}

//#include <stdio.h> 
//int	main(void)
//{
//	char *s = "tttifffffffoiiiikk";
//	size_t r = ft_len_outer(s, 'i');
//	char **ptr = ft_split(s, 'i');
//
//	for(size_t i = 0; i < r; i++)
//		printf("Mine: %s\n", ptr[i]);
//	return (0);
//}
