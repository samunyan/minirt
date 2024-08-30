/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:51:45 by gscarama          #+#    #+#             */
/*   Updated: 2023/06/01 14:45:11 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	get_hit_info_plane(t_obj *obj, t_ray *ray, double t)
{
	t_hit	info;

	ft_bzero(&info, sizeof(info));
	info.obj = obj;
	info.t_nearest = t;
	info.point = get_hit_point(*ray, t);
	info.normal = obj->orientation;
	info.point = v_add(info.point, v_scale(info.normal, EPSILON));
	info.viewdirection = v_scale(ray->v_dir, -1);
	return (info);
}

int	hit_plane(t_obj *obj, t_ray *ray, double *t)
{
	t_vec3	v;
	double	denom;
	double	dist;

	denom = v_dot(obj->orientation, ray->v_dir);
	if (fabs(denom) > EPSILON)
	{
		v = v_sub(obj->position, ray->p_ori);
		dist = v_dot(v, obj->orientation) / denom;
		if (dist < EPSILON || dist >= *t)
			return (false);
		*t = dist;
		return (true);
	}
	return (false);
}
