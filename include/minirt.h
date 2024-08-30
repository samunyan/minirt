/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:01:24 by samunyan          #+#    #+#             */
/*   Updated: 2023/05/31 16:07:21 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <float.h>
# include <limits.h>
# include <stdio.h>

# include "mlx.h"
# include "libft.h"

# include "gmath.h"
# include "material.h"
# include "object.h"
# include "camera.h"
# include "light.h"
# include "scene.h"
# include "parsing.h"
# include "error.h"
# include "image.h"
# include "hook.h"
# include "rgb_pixel.h"
# include "ray.h"
# include "shade.h"

# define NB_SPECS_LIGHT_AMBIENT	3
# define NB_SPECS_CAMERA		4
# define NB_SPECS_LIGHT_DIFFUSE	4
# define NB_SPECS_OBJ_SPHERE	4
# define NB_SPECS_OBJ_PLANE		4
# define NB_SPECS_OBJ_CYLINDER	6

# define EPSILON	1e-8
#endif
