/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2023/06/01 14:18:46 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_image(t_scene *scene)
{
	scene->win = (t_window *)malloc(sizeof(t_window));
	if (!scene->win)
		return (-1);
	scene->win->img = (t_image *)malloc(sizeof(t_image));
	if (!scene->win->img)
		return (-1);
	scene->win->ptr = mlx_init();
	if (!scene->win->ptr)
		return (-1);
	scene->win->win = mlx_new_window(scene->win->ptr,
			scene->width, scene->height, "MiniRT");
	if (!scene->win->win)
		return (-1);
	scene->win->img->img = mlx_new_image(scene->win->ptr,
			scene->width, scene->height);
	scene->win->img->addr = mlx_get_data_addr(scene->win->img->img,
			&scene->win->img->pxlsize,
			&scene->win->img->sline, &scene->win->img->endian);
	return (0);
}

void	clear_window(t_window *win)
{
	if (win)
	{
		if (win->win)
			mlx_destroy_window(win->ptr, win->win);
		if (win->img)
		{
			if (win->img->img)
				mlx_destroy_image(win->ptr, win->img->img);
			free(win->img);
		}
		free (win);
	}
}
