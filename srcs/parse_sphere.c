/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:14:05 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:50:09 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	sphere_is_valid(t_obj *obj, int line_nb)
{
	(void)obj;
	(void)line_nb;
	return (true);
}

int	parse_sphere(t_scene *scene, char **data, int line_nb)
{
	t_obj	*obj;

	if (arrlen(data) != NB_SPECS_OBJ_SPHERE)
		return (mrt_parse_error(ERRNUM_SPECS, line_nb, NULL));
	obj = add_obj(&(scene->objs));
	if (!obj)
		return (false);
	if (!str_to_3_doubles(data[1], &(obj->position), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[1]));
	if (!str_to_1_double(data[2], &(obj->scale.x), false))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, data[2]));
	if (!parse_material_default_attr(data[3], &obj->material, line_nb))
		return (false);
	obj->scale.y = obj->scale.x;
	obj->scale.z = obj->scale.x;
	obj->hit = &hit_sphere;
	obj->get_hit_info = &get_hit_info_sphere;
	return (sphere_is_valid(obj, line_nb));
}
