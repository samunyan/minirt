/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:42:56 by samunyan          #+#    #+#             */
/*   Updated: 2023/05/31 12:34:15 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*add_obj(t_obj **objs)
{
	t_obj	*nw;
	t_obj	*current;

	nw = (t_obj *)ft_malloc(sizeof(t_obj));
	if (!nw)
		return (NULL);
	ft_bzero(nw, sizeof(*nw));
	if (!*objs)
		*objs = nw;
	else
	{
		current = *objs;
		while (current->next)
			current = current->next;
		current->next = nw;
	}
	return (nw);
}

void	clear_objs(t_obj **objs)
{
	t_obj	*current;
	t_obj	*next;

	current = *objs;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
