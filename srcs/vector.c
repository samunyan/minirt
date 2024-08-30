/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2023/04/26 13:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v_set(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	v_len_sqr(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	v_len(t_vec3 v)
{
	return (sqrt(v_len_sqr(v)));
}

t_vec3	v_norm(t_vec3 v)
{
	return (v_scale(v, 1 / v_len(v)));
}

double	magnitude(t_vec3 *v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}
