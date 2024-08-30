/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2023/05/31 12:40:35 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v_add(t_vec3 v, t_vec3 u)
{
	return (v_set((v.x + u.x), (v.y + u.y), (v.z + u.z)));
}

t_vec3	v_sub(t_vec3 v, t_vec3 u)
{
	return (v_set((v.x - u.x), (v.y - u.y), (v.z - u.z)));
}

t_vec3	v_scale(t_vec3 v, double f)
{
	return (v_set((f * v.x), (f * v.y), (f * v.z)));
}

t_vec3	v_cross(t_vec3 v, t_vec3 u)
{
	return (v_set(((v.y * u.z) - (v.z * u.y)),
			((v.z * u.x) - (v.x * u.z)),
			((v.x * u.y) - (v.y * u.x))));
}

double	v_dot(t_vec3 v, t_vec3 u)
{
	return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
}
