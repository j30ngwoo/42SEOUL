/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:03:34 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/24 18:46:25 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*temp;

	head = 0;
	while (lst)
	{
		temp = f(lst->content);
		new_node = ft_lstnew(temp);
		if (new_node == 0)
		{
			del(temp);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}
