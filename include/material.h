/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:26:20 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 13:55:18 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "minirt.h"

# define DEFAULT_PHONG_AMBIENT 0.3
# define DEFAULT_PHONG_DIFFUSE 0.9
# define DEFAULT_PHONG_SPECULAR 0.9
# define DEFAULT_PHONG_SHININESS 200

typedef struct s_mtl {
	t_vec3	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_mtl;

#endif