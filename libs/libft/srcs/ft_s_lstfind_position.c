/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstfind_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:26:31 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:26:32 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_s_lstfind_position(t_s_list *lst, t_s_list *node)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst == node)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}
