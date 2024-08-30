/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmath.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:19:11 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 11:33:17 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bhaskara(double a, double b, double c, double *res)
{
	double	sqrt_discriminant;
	double	aux[2];

	sqrt_discriminant = sqrt(pow(b, 2) - 4 * a * c);
	aux[0] = (-b - sqrt_discriminant) / (2 * a);
	aux[1] = (-b + sqrt_discriminant) / (2 * a);
	if (aux[0] < aux[1])
	{
		res[0] = aux[0];
		res[1] = aux[1];
	}
	else
	{
		res[0] = aux[1];
		res[1] = aux[0];
	}
}

t_vec3	clamp(t_vec3 *v, double min, double max)
{
	t_vec3	res;

	if (v->x > max)
		res.x = max;
	else if (v->x < min)
		res.x = min;
	else
		res.x = v->x;
	if (v->y > max)
		res.y = max;
	else if (v->y < min)
		res.y = min;
	else
		res.y = v->y;
	if (v->z > max)
		res.z = max;
	else if (v->z < min)
		res.z = min;
	else
		res.z = v->z;
	return (res);
}

t_vec3	reflect(t_vec3 in, t_vec3 normal)
{
	return (v_sub(in, v_scale(normal, 2 * v_dot(in, normal))));
}
