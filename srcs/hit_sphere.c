/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:15:13 by gscarama          #+#    #+#             */
/*   Updated: 2023/06/01 14:50:33 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	hit_is_inside(t_hit *hit_info)
{
	return (v_dot(hit_info->viewdirection, hit_info->normal) < 0);
}

t_hit	get_hit_info_sphere(t_obj *obj, t_ray *ray, double t)
{
	t_hit	info;

	ft_bzero(&info, sizeof(info));
	info.obj = obj;
	info.t_nearest = t;
	info.point = get_hit_point(*ray, t);
	info.normal = v_norm(v_sub(info.point, obj->position));
	info.viewdirection = v_scale(ray->v_dir, -1);
	if (hit_is_inside(&info))
		info.normal = v_scale(info.normal, -1);
	info.point = v_add(info.point, v_scale(info.normal, EPSILON));
	return (info);
}

static void	swap_doubles(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	hit_sphere(t_obj *obj, t_ray *ray, double *t)
{
	t_vec3	v_sp2ray;
	double	dist[2];

	v_sp2ray = v_sub(ray->p_ori, obj->position);
	bhaskara(v_len_sqr(ray->v_dir), 2 * v_dot(ray->v_dir, v_sp2ray),
		v_dot(v_sp2ray, v_sp2ray) - pow(obj->scale.x / 2, 2), dist);
	if (dist[0] > dist[1])
		swap_doubles(&dist[0], &dist[1]);
	if (dist[0] < 0)
		dist[0] = dist[1];
	if (dist[0] < EPSILON || dist[0] >= *t)
		return (false);
	*t = dist[0];
	return (true);
}
