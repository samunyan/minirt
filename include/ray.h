/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:24:53 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:52:37 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"

typedef struct s_hit
{
	double	t_nearest;
	t_obj	*obj;
	t_vec3	normal;
	t_vec3	point;
	t_vec3	viewdirection;
}	t_hit;

typedef struct s_ray
{
	t_vec3			p_ori;
	t_vec3			v_dir;
}				t_ray;

int		hit_plane(t_obj *obj, t_ray *ray, double *t);
int		hit_sphere(t_obj *obj, t_ray *ray, double *t);
int		hit_cylinder(t_obj *obj, t_ray *ray, double *t);
t_hit	get_hit_info_plane(t_obj *obj, t_ray *ray, double t);
t_hit	get_hit_info_sphere(t_obj *obj, t_ray *ray, double t);
t_hit	get_hit_info_cylinder(t_obj *obj, t_ray *ray, double t);
t_vec3	get_hit_point(t_ray ray, double t);
t_ray	gen_cam_ray(t_scene *scene, double x, double y);
t_ray	set_ray(t_vec3 orig, t_vec3 dir);
t_vec3	cast_ray(t_ray *camera_ray, t_obj *objs, t_light *lights);
int		trace(t_ray *ray, t_obj *objs, t_hit *hit_info);

#endif