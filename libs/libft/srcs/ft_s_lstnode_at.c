/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstnode_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:58:04 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/30 21:58:58 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s_list	*ft_s_lstnode_at(t_s_list *list, int index)
{
	int	i;

	i = 0;
	while (list)
	{
		if (i == index)
			return (list);
		i++;
		list = list->next;
	}
	return (NULL);
}
