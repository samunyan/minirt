/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:42:57 by samunyan          #+#    #+#             */
/*   Updated: 2023/05/31 12:20:53 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

typedef enum e_light_type {
	AMBIENT = 1,
	POINT
}	t_light_type;

typedef struct s_light {
	t_light_type	type;
	t_vec3			position;
	double			intensity;
	t_vec3			color;
	struct s_light	*next;
}	t_light;

t_light	*add_light(t_light **lights);
int		get_nb_lights(t_light *lights);
void	clear_lights(t_light **lights);

#endif