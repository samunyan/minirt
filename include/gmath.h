/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:50:56 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 11:33:31 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMATH_H
# define GMATH_H

# include "minirt.h"

typedef struct s_vec3 {
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	v_set(double x, double y, double z);
t_vec3	v_add(t_vec3 v, t_vec3 u);
t_vec3	v_sub(t_vec3 v, t_vec3 u);
t_vec3	v_scale(t_vec3 v, double f);
t_vec3	v_cross(t_vec3 v, t_vec3 u);
double	v_dot(t_vec3 v, t_vec3 u);
double	v_len_sqr(t_vec3 v);
double	v_len(t_vec3 v);
t_vec3	v_norm(t_vec3 v);
double	magnitude(t_vec3 *v);
void	bhaskara(double a, double b, double c, double *res);
t_vec3	reflect(t_vec3 in, t_vec3 normal);

#endif
