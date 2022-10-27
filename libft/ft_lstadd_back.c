/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:37:38 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/14 09:50:47 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp != NULL)
		{
			if (temp->next == NULL)
			{
				temp->next = new;
				return ;
			}
			temp = temp->next;
		}
	}
}

//#include <stdio.h>
//int	main(void)
//{
//	t_list *head = ft_lstnew("Node 1");
//	t_list *sec = ft_lstnew("Node 2");
//	t_list *third = ft_lstnew("Node 3");
//	t_list *fourth = ft_lstnew(NULL);
//
//	ft_lstadd_back(&head, sec);
//	ft_lstadd_back(&head, third);
//	ft_lstadd_back(&head, fourth);
//	while (head != NULL)
//	{
//		printf("%s\n", head->content);
//		head = head->next;
//	}
//	return (0);
//}
