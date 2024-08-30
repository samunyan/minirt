/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:36:32 by gscarama          #+#    #+#             */
/*   Updated: 2023/06/01 14:51:44 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	sub_product(t_ray *ray, t_obj *cy, t_vec3 *v0, t_vec3 *v1)
{
	(*v0) = v_sub(ray->v_dir, v_scale(cy->orientation,
				v_dot(ray->v_dir, cy->orientation)));
	(*v1) = v_sub(v_sub(ray->p_ori, cy->position),
			v_scale(cy->orientation,
				v_dot(v_sub(ray->p_ori, cy->position), cy->orientation)));
}

static double	cy_calc(t_ray ray, t_obj cy, int ret[2], double *y)
{
	t_vec3	v[2];
	t_vec3	v_cy2ray;
	double	rest[2];
	double	dist[2];

	sub_product(&ray, &cy, &v[0], &v[1]);
	bhaskara(v_len_sqr(v[0]), 2 * v_dot(v[0], v[1]),
		v_len_sqr(v[1]) - pow(cy.scale.x / 2, 2), rest);
	v_cy2ray = v_sub(cy.position, ray.p_ori);
	dist[0] = v_dot(cy.orientation,
			v_sub(v_scale(ray.v_dir, rest[0]), v_cy2ray));
	dist[1] = v_dot(cy.orientation,
			v_sub(v_scale(ray.v_dir, rest[1]), v_cy2ray));
	ret[0] = (dist[0] >= 0 && dist[0] <= cy.scale.y && rest[0] > EPSILON);
	ret[1] = (dist[1] >= 0 && dist[1] <= cy.scale.y && rest[1] > EPSILON);
	if (ret[0] == false && ret[1] == true)
	{
		*y = dist[1];
		return (rest[1]);
	}
		*y = dist[0];
	return (rest[0]);
}

t_hit	get_hit_info_cylinder(t_obj *obj, t_ray *ray, double t)
{
	t_hit	info;
	int		ret[2];
	double	y;

	cy_calc(*ray, *obj, ret, &y);
	info.obj = obj;
	info.t_nearest = t;
	info.point = get_hit_point(*ray, t);
	info.viewdirection = v_scale(ray->v_dir, -1);
	if (ret[0] == false && ret[1] == true)
		info.normal = v_scale(info.normal, -1);
	else
		info.normal = v_norm(v_sub(info.point,
					v_add(v_scale(obj->orientation, y), obj->position)));
	info.point = v_add(info.point, v_scale(info.normal, EPSILON));
	return (info);
}

int	hit_cylinder(t_obj *obj, t_ray *ray, double *t)
{
	int		ret[2];
	double	dist;

	dist = cy_calc(*ray, *obj, ret, &dist);
	if (*t > dist && *t != DBL_MAX)
		return (false);
	*t = dist;
	return (ret[0] || ret[1]);
}
