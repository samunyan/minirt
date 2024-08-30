/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:31:30 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 15:02:05 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scene_is_valid(t_scene *scene)
{
	if (get_nb_lights(scene->lights) != 2
		|| scene->lights->type == scene->lights->next->type
		|| get_nb_cameras(scene->cameras) != 1)
	{
		mrt_error(mrt_strerror, ERRNUM_SCENE, NULL);
		return (false);
	}
	return (true);
}
