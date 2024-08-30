/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:43:28 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 13:51:48 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*add_light(t_light **lights)
{
	t_light	*nw;
	t_light	*current;

	nw = (t_light *)ft_malloc(sizeof(t_light));
	if (!nw)
		return (NULL);
	ft_bzero(nw, sizeof(*nw));
	if (!*lights)
		*lights = nw;
	else
	{
		current = *lights;
		while (current->next)
			current = current->next;
		current->next = nw;
	}
	return (nw);
}

int	get_nb_lights(t_light *lights)
{
	int	i;

	i = 0;
	while (lights)
	{
		i++;
		lights = lights->next;
	}
	return (i);
}

void	clear_lights(t_light **lights)
{
	t_light	*current;
	t_light	*next;

	current = *lights;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
