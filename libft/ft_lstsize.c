/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:08:33 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/12 16:20:35 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

//#include <stdio.h>
//int	main(void)
//{
//	t_list *head = ft_lstnew("Node 2");
//	t_list *sec = ft_lstnew("Node 1");
//	ft_lstadd_front(&head, sec);
//
//	int	len = ft_lstsize(sec);
//	printf("%d\n", len);
//	return (0);
//}
