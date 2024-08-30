/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:56:02 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 19:56:03 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_s_lstadd_back(t_s_list **lst, t_s_list *new)
{
	t_s_list	*current;

	if (!*lst)
	{
		ft_s_lstadd_front(lst, new);
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}
