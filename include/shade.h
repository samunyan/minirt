/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:16:01 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 11:37:48 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADE_H
# define SHADE_H

# include "minirt.h"

t_vec3	shade_hit(t_hit *hit_info, t_light *lights, t_obj *objs);

#endif
