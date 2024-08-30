/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:15:43 by samunyan          #+#    #+#             */
/*   Updated: 2023/05/31 12:13:54 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"
# include "camera.h"
# include "light.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_scene{
	int				width;
	int				height;
	t_obj			*objs;
	t_light			*lights;
	struct s_window	*win;
	struct s_camera	*cameras;
}	t_scene;

t_scene	*init_scene(char *filepath);
void	clear_scene(t_scene **scene);
void	create_scene(t_scene *scene);

#endif
