/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:57:53 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 19:57:54 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s_list	*ft_s_lstlast(t_s_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
