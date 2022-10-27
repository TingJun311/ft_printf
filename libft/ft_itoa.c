/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:04:07 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 15:11:27 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	void	ft_reverse_str(char *s)
{
	size_t	i;
	char	temp;
	size_t	len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (i < (ft_strlen(s) / 2))
	{
		temp = s[len];
		s[len] = s[i];
		s[i] = temp;
		len--;
		i++;
	}
}

static void	check_itoa(char *ptr, int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		ptr[i++] = '-';
		ptr[i++] = '8';
		n = 214748364;
	}
	if (n < 0)
	{
		ptr[i++] = '-';
		n = -n;
	}
	if (n == 0)
		ptr[i++] = '0';
	while (n != 0)
	{
		ptr[i++] = (n % 10) + '0';
		n = n / 10;
	}
	ptr[i] = '\0';
}

static size_t	count_size(int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;
	int		temp;
	size_t	isneg;

	i = 0;
	isneg = 0;
	temp = n;
	if (n < 0)
		isneg = 1;
	if (n == 0)
		i = 1;
	else
		i = count_size(n);
	ptr = (char *)malloc(sizeof(char) * (i + 1 + isneg));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	check_itoa(ptr, n);
	if (isneg == 1)
		ft_reverse_str(ptr + 1);
	else
		ft_reverse_str(ptr);
	return (ptr);
}

//#include <limits.h>
//#include <stdio.h>
//int	main(void)
//{
//	char	*j = ft_itoa(-123456);
//	printf("%s\n", j);
//	printf("%zu\n", ft_strlen(j));
//	return (0);
//}
