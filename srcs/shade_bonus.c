/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:08:59 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 11:56:38 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_ambient_lighting(t_light *ambient_light, t_hit *hit_info)
{
	return (mult_rgb(hit_info->obj->material.color,
			scale_rgb(ambient_light->color,
				ambient_light->intensity * hit_info->obj->material.ambient)));
}

t_vec3	get_diffuse_lighting(t_light *point_light, t_hit *hit_info)
{
	t_vec3	light_dir;
	double	d;

	light_dir = v_norm(v_sub(point_light->position, hit_info->point));
	d = v_dot(hit_info->normal, light_dir);
	if (d < 0)
		return (v_set(0, 0, 0));
	return (mult_rgb(hit_info->obj->material.color,
			scale_rgb(point_light->color,
				point_light->intensity * hit_info->obj->material.diffuse * d)));
}

t_vec3	get_specular_lighting(t_light *point_light, t_hit *hit_info)
{
	t_vec3	reflect_v;
	t_vec3	light_dir;
	double	d;

	light_dir = v_norm(v_sub(point_light->position, hit_info->point));
	d = v_dot(hit_info->normal, light_dir);
	if (d < 0)
		return (v_set(0, 0, 0));
	reflect_v = reflect(v_scale(light_dir, -1), hit_info->normal);
	d = v_dot(reflect_v, hit_info->viewdirection);
	if (d < 0)
		return (v_set(0, 0, 0));
	d = pow(d, hit_info->obj->material.shininess);
	return (mult_rgb(hit_info->obj->material.color,
			scale_rgb(point_light->color, point_light->intensity
				* hit_info->obj->material.specular * d)));
}

int	hit_is_shadowed(t_hit *hit_info, t_light *point_light, t_obj *objs)
{
	t_vec3	light_dir;
	t_hit	shadow_info;
	double	distance;
	t_ray	shadow_ray;

	light_dir = v_sub(point_light->position, hit_info->point);
	distance = magnitude(&light_dir);
	ft_bzero(&shadow_info, sizeof(shadow_info));
	shadow_info.t_nearest = distance;
	light_dir = v_norm(light_dir);
	shadow_ray = set_ray(hit_info->point, light_dir);
	return (trace(&shadow_ray, objs, &shadow_info));
}

t_vec3	shade_hit(t_hit *hit_info, t_light *lights, t_obj *objs)
{
	t_vec3	color;

	color = v_set(0, 0, 0);
	while (lights)
	{
		if (lights->type == AMBIENT)
			color = add_rgb(color, get_ambient_lighting(lights, hit_info));
		else if (lights->type == POINT
			&& !hit_is_shadowed(hit_info, lights, objs))
			color = add_rgb(color,
					add_rgb(get_diffuse_lighting(lights, hit_info),
						get_specular_lighting(lights, hit_info)));
		lights = lights->next;
	}
	return (color);
}
