/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:56:32 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 19:56:33 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_s_lstclear(t_s_list **lst, void (*del)(void*))
{
	t_s_list	*current;
	t_s_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_s_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
