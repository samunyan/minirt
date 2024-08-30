/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2023/04/26 13:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_hook(int key, t_scene *scene)
{
	if (key == KEY_ESCAPE)
	{
		clear_scene(&scene);
		exit(0);
	}
	return (1);
}

int	hook_exit(t_scene *scene)
{
	clear_scene(&scene);
	exit(0);
}
