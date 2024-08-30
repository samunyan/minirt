/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:24:44 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 15:02:11 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	camera_is_valid(t_camera *camera, int line_nb)
{
	if (!double_is_in_range(camera->fov, 0, 180)
		|| !(vec3_is_in_range(&camera->orientation, -1, 1)))
		return (mrt_parse_error(ERRNUM_RANGE, line_nb, NULL));
	if (magnitude(&(camera->orientation)) == 0)
		return (mrt_parse_error(ERRNUM_UNIT, line_nb, NULL));
	camera->orientation = v_norm(camera->orientation);
	camera->fov *= M_PI / 180;
	return (true);
}

int	parse_camera(t_scene *scene, char **data, int line_nb)
{
	t_camera	*camera;

	camera = add_camera(&(scene->cameras));
	if (!camera)
		return (false);
	if (arrlen(data) != NB_SPECS_CAMERA)
		return (mrt_parse_error(ERRNUM_SPECS, line_nb, NULL));
	if (!str_to_3_doubles(data[1], &(camera->position), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[1]));
	if (!str_to_3_doubles(data[2], &(camera->orientation), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[2]));
	if (!str_to_1_double(data[3], &(camera->fov), true))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[3]));
	return (camera_is_valid(camera, line_nb));
}
