/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:42:58 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 11:37:35 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_PIXEL_H
# define RGB_PIXEL_H

# include "minirt.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
int		rgb_to_int(t_vec3 color);
t_vec3	clamp(t_vec3 *v, double min, double max);
t_vec3	mult_rgb(t_vec3 a, t_vec3 b);
t_vec3	add_rgb(t_vec3 a, t_vec3 b);
t_vec3	scale_rgb(t_vec3 a, double s);

#endif
