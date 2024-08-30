/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstfind_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:22:30 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:22:33 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s_list	*ft_s_lstfind_content(t_s_list *lst, void *content)
{
	while (lst)
	{
		if (lst->content == content)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
