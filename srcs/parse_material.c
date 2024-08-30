/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:26:29 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:50:33 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	material_is_valid(t_mtl *mtl, int line_nb)
{
	if (!vec3_is_in_range(&(mtl->color), 0., 1.))
		return (mrt_parse_error(ERRNUM_RANGE, line_nb, NULL));
	return (true);
}

int	parse_material_default_attr(char *src, t_mtl *mtl, int line_nb)
{
	if (!str_to_3_doubles(src, &(mtl->color), true))
		return (mrt_parse_error(ERRNUM_FORMAT, line_nb, src));
	mtl->color = v_scale(mtl->color, 1. / 255);
	mtl->ambient = DEFAULT_PHONG_AMBIENT;
	mtl->diffuse = DEFAULT_PHONG_DIFFUSE;
	mtl->specular = DEFAULT_PHONG_SPECULAR;
	mtl->shininess = DEFAULT_PHONG_SHININESS;
	return (material_is_valid(mtl, line_nb));
}
