/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:22:40 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 13:54:57 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	light_is_valid(t_light *light, int line_nb)
{
	if (!double_is_in_range(light->intensity, 0., 1.)
		|| !vec3_is_in_range(&(light->color), 0., 1.))
		return (mrt_parse_error(ERRNUM_RANGE, line_nb, NULL));
	return (true);
}

int	parse_ambient_light(t_scene *scene, char **data, int line_nb)
{
	t_light	*light;

	light = add_light(&(scene->lights));
	if (!light)
		return (false);
	if (arrlen(data) != NB_SPECS_LIGHT_AMBIENT)
		return (mrt_parse_error(ERRNUM_SPECS, line_nb, NULL));
	light->type = AMBIENT;
	if (!str_to_1_double(data[1], &(light->intensity), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[1]));
	if (!str_to_3_doubles(data[2], &(light->color), true))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[2]));
	light->color = v_scale(light->color, 1. / 255);
	return (light_is_valid(light, line_nb));
}

int	parse_diffuse_light(t_scene *scene, char **data, int line_nb)
{
	t_light	*light;

	light = add_light(&(scene->lights));
	if (!light)
		return (false);
	if (arrlen(data) != NB_SPECS_LIGHT_DIFFUSE)
		return (mrt_parse_error(ERRNUM_SPECS, line_nb, NULL));
	light->type = POINT;
	if (!str_to_3_doubles(data[1], &(light->position), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[1]));
	if (!str_to_1_double(data[2], &(light->intensity), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[2]));
	if (!str_to_3_doubles(data[3], &(light->color), true))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[3]));
	light->color = v_scale(light->color, 1. / 255);
	return (light_is_valid(light, line_nb));
}
