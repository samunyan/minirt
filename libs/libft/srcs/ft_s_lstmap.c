/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:03:49 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 20:03:50 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s_list	*ft_s_lstmap(t_s_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_s_list	*new_head;
	t_s_list	*new;
	t_s_list	*tmp;

	new_head = NULL;
	while (lst)
	{
		new = ft_s_lstnew(f(lst->content));
		if (!new)
		{
			while (new_head)
			{
				tmp = new_head->next;
				ft_s_lstdelone(new_head, del);
				new_head = tmp;
			}
			return (NULL);
		}
		ft_s_lstadd_back(&new_head, new);
		lst = lst->next;
	}
	return (new_head);
}
