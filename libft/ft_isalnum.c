/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:10:45 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/03 16:20:32 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function its to return 1 if the arguments was a base 10 digit and not
// decimal points, or is a alphabet in decimal set ascii table 

int	ft_isalnum(int n)
{
	return (ft_isdigit(n) || ft_isalpha(n));
}

//#include<stdio.h>
//int	main(void)
//{
//	printf("%d\n", ft_isalnum('D'));
//	return (0);
//}
