/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:42:58 by samunyan          #+#    #+#             */
/*   Updated: 2023/05/31 12:43:21 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "minirt.h"

typedef struct s_ray	t_ray;

typedef struct s_obj {
	t_vec3			position;
	t_vec3			orientation;
	t_vec3			scale;
	t_mtl			material;
	int				(*hit)(struct s_obj *obj, t_ray *ray, double *t_nearest);
	struct s_hit	(*get_hit_info)(struct s_obj *obj, t_ray *ray, double t);
	struct s_obj	*next;
}	t_obj;

t_obj	*add_obj(t_obj **objs);
void	clear_objs(t_obj **objs);
#endif