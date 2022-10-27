/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:37:38 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/11 11:17:50 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function is to check the agruments its a decimal digit chracter or not
// int its a combination of base 10, so this function return 1
// if the argument its between or equal to 0 and 9.

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

//#include <stdio.h>
//int	main(void)
//{
//	printf("%d\n", ft_isdigit('8'));
//	return (0);
//}
