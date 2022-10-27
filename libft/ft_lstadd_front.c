/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:52:22 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 08:57:50 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

//#include <stdio.h>
//int	main(void)
//{
//	t_list *node = NULL;
//	t_list *node1 = ft_lstnew((void *)1);
//	ft_lstadd_front(&node, node1);
//	
//	while (node1 != NULL)
//	{
//		printf("%s->", node1->content);
//		node1 = node1->next;
//	}
//	return (0);
//}
