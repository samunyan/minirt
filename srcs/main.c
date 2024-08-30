/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:38:54 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 13:53:24 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	display_scene(t_scene *scene)
{
	mlx_put_image_to_window(scene->win->img->addr,
		scene->win->win, scene->win->img->img, 0, 0);
	mlx_hook(scene->win->win, 2, 4, key_hook, scene);
	mlx_hook(scene->win->win, XDESTROY_NOTIFY, 1L << 17, hook_exit, scene);
	mlx_loop(scene->win->ptr);
}

int	main(int ac, char *av[])
{
	t_scene	*scene;

	if (ac != 2)
	{
		mrt_error(mrt_strerror, ERRNUM_ARGS, NULL);
		return (EXIT_FAILURE);
	}
	scene = init_scene(av[1]);
	if (!scene)
		return (EXIT_FAILURE);
	if (init_image(scene))
	{
		clear_scene(&scene);
		return (EXIT_FAILURE);
	}
	create_scene(scene);
	display_scene(scene);
	clear_scene(&scene);
	return (EXIT_SUCCESS);
}
