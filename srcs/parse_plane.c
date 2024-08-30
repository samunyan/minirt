/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:14:16 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:50:34 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	plane_is_valid(t_obj *obj, int line_nb)
{
	if (!(vec3_is_in_range(&obj->orientation, -1, 1)))
		return (mrt_parse_error(ERRNUM_RANGE, line_nb, NULL));
	if (magnitude(&(obj->orientation)) == 0)
		return (mrt_parse_error(ERRNUM_UNIT, line_nb, NULL));
	obj->orientation = v_norm(obj->orientation);
	return (true);
}

int	parse_plane(t_scene *scene, char **data, int line_nb)
{
	t_obj	*obj;

	if (arrlen(data) != NB_SPECS_OBJ_PLANE)
		return (mrt_parse_error(ERRNUM_SPECS, line_nb, NULL));
	obj = add_obj(&(scene->objs));
	if (!obj)
		return (false);
	if (!str_to_3_doubles(data[1], &(obj->position), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[1]));
	if (!str_to_3_doubles(data[2], &(obj->orientation), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[2]));
	if (!parse_material_default_attr(data[3], &obj->material, line_nb))
		return (false);
	obj->hit = &hit_plane;
	obj->get_hit_info = &get_hit_info_plane;
	return (plane_is_valid(obj, line_nb));
}
