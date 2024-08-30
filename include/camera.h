/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:43:05 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:40:43 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"
# include "scene.h"

typedef struct s_camera {
	t_vec3			position;
	t_vec3			orientation;
	double			fov;
	t_vec3			hor;
	t_vec3			ver;
	t_vec3			llc;
	struct s_camera	*next;
}	t_camera;

t_camera	*add_camera(t_camera **cameras);
int			get_nb_cameras(t_camera *cameras);
void		clear_cameras(t_camera **cameras);
void		get_cam_info(t_scene *scene, t_camera *cam);

#endif
