/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:43:30 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 12:00:59 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*add_camera(t_camera **cameras)
{
	t_camera	*nw;

	nw = (t_camera *)ft_malloc(sizeof(*nw));
	if (!nw)
		return (NULL);
	ft_bzero(nw, sizeof(*nw));
	if (!*cameras)
		*cameras = nw;
	else
		(*cameras)->next = nw;
	return (nw);
}

int	get_nb_cameras(t_camera *cameras)
{
	int	i;

	i = 0;
	while (cameras)
	{
		i++;
		cameras = cameras->next;
	}
	return (i);
}

void	clear_cameras(t_camera **cameras)
{
	t_camera	*current;
	t_camera	*next;

	current = *cameras;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

static t_vec3	set_upvector(t_vec3 *cam_ori, t_vec3 *w)
{
	if (!fabs(cam_ori->x) && !fabs(cam_ori->z))
	{
		if (cam_ori->y > 0)
			return (v_cross(v_set(0, 0, -1), *w));
		else
			return (v_cross(v_set(0, 0, 1), *w));
	}
	else
		return (v_cross(v_set(0, 1, 0), *w));
}

void	get_cam_info(t_scene *scene, t_camera *cam)
{
	double	vp[2];
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	while (cam)
	{
		vp[0] = 2 * tan(cam->fov / 2);
		vp[1] = vp[0] * scene->height / scene->width;
		w = v_norm(v_scale(cam->orientation, -1));
		u = set_upvector(&cam->orientation, &w);
		v = v_cross(w, u);
		cam->hor = v_scale(u, vp[0]);
		cam->ver = v_scale(v, vp[1]);
		cam->llc = v_sub(cam->position, v_scale(cam->hor, 0.5));
		cam->llc = v_sub(cam->llc, v_scale(cam->ver, 0.5));
		cam->llc = v_sub(cam->llc, w);
		cam = cam->next;
	}
}
