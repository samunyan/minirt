/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:31:42 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 15:02:13 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ambient_light_is_present(t_light *lights)
{
	while (lights)
	{
		if (lights->type == AMBIENT)
			return (true);
		lights = lights->next;
	}
	return (false);
}

int	scene_is_valid(t_scene *scene)
{
	if (get_nb_lights(scene->lights) < 2
		|| !ambient_light_is_present(scene->lights)
		|| get_nb_cameras(scene->cameras) != 1)
	{
		mrt_error(mrt_strerror, ERRNUM_SCENE, NULL);
		return (false);
	}
	return (true);
}
