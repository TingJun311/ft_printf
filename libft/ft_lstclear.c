/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:33:13 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 09:56:06 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	while (*lst != NULL && lst != NULL)
	{
		next_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = (*lst)->next;
		*lst = next_node;
	}
}

//#include <stdio.h>
//int	main(void)
//{
//	t_list *head = ft_lstnew(malloc(1));
//
//	for (int i = 0; i < 10; ++i)
//		ft_lstadd_front(&head, ft_lstnew(malloc(1)));
//	ft_lstclear(&head, free);
//	while (head != NULL)
//	{
//		printf("%s->", head->content);
//		head = head->next;
//	}
//	return (0);
//}
