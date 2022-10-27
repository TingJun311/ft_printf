/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:25:33 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 10:08:30 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

//#include <stdio.h>
//#include <strings.h>
//int	main(void)
//{
//	char str[50] = "12345 6789";
//	char str1[50] = "12345 6789";
//	bzero(str, 2);
//	ft_bzero(str1, 2);
//	printf("%s\n", &str[2]);
//	printf("%s\n", &str1[2]);
//	return (0);
//}
