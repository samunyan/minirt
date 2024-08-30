/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:15:53 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 12:30:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*init_scene(char *filepath)
{
	t_scene	*scene;

	scene = (t_scene *)ft_malloc(sizeof(*scene));
	if (!scene)
		return (NULL);
	ft_bzero(scene, sizeof(*scene));
	scene->height = HEIGHT;
	scene->width = WIDTH;
	if (!parse(scene, filepath))
		clear_scene(&scene);
	else
		get_cam_info(scene, scene->cameras);
	return (scene);
}

void	create_scene(t_scene *scene)
{
	t_ray	cam_ray;
	t_vec3	color;
	int		x;
	int		y;

	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			cam_ray = gen_cam_ray(scene,
					(double)x / scene->width, (double)y / scene->height);
			color = cast_ray(&cam_ray, scene->objs, scene->lights);
			my_mlx_pixel_put(scene->win->img, scene->width - x - 1,
				scene->height - y - 1, rgb_to_int(color));
			x++;
		}
		y++;
	}
}

void	clear_scene(t_scene **scene)
{
	if (!*scene)
		return ;
	clear_cameras(&((*scene)->cameras));
	clear_lights(&((*scene)->lights));
	clear_objs(&((*scene)->objs));
	clear_window((*scene)->win);
	free(*scene);
	*scene = NULL;
}
