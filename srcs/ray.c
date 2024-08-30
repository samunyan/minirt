/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:24:28 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 15:03:55 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	set_ray(t_vec3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.p_ori = orig;
	ray.v_dir = dir;
	return (ray);
}

t_ray	gen_cam_ray(t_scene *scene, double x, double y)
{
	t_ray	ray;

	ray.p_ori = scene->cameras->position;
	ray.v_dir = v_add(v_scale(scene->cameras->hor, x),
			v_scale(scene->cameras->ver, y));
	ray.v_dir = v_add(ray.v_dir, scene->cameras->llc);
	ray.v_dir = v_norm(v_sub(ray.v_dir, ray.p_ori));
	return (ray);
}

int	trace(t_ray *ray, t_obj *objs, t_hit *hit_info)
{
	double	t;

	while (objs)
	{
		t = DBL_MAX;
		if (objs->hit(objs, ray, &t) && t < hit_info->t_nearest)
			*hit_info = objs->get_hit_info(objs, ray, t);
		objs = objs->next;
	}
	return (hit_info->obj != NULL);
}

t_vec3	cast_ray(t_ray *camera_ray, t_obj *objs, t_light *lights)
{
	t_vec3	color;
	t_hit	hit_info;

	ft_bzero(&hit_info, sizeof(hit_info));
	hit_info.t_nearest = DBL_MAX;
	color = v_set(0, 0, 0);
	if (trace(camera_ray, objs, &hit_info))
		color = shade_hit(&hit_info, lights, objs);
	return (color);
}

t_vec3	get_hit_point(t_ray ray, double t)
{
	return (v_add(ray.p_ori, v_scale(ray.v_dir, t)));
}
