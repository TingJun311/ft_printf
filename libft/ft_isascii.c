/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:05:56 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/03 16:29:06 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function return 1 if the argument its a ascii decimal set value.
// Else return 0, interger value has to be in between or equal to
// 0 to 127

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

//#include <stdio.h>
//int	main(void)
//{
//	char	c = 127;
//
//	printf("%d\n", ft_isascii(c));
//	printf("%c\n", c);
//	return (0);
//}
