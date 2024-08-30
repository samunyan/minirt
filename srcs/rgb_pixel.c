/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2023/06/02 11:31:37 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->sline + x * (img->pxlsize / 8));
	*(unsigned int *)dst = color;
}

t_vec3	mult_rgb(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (clamp(&res, 0, 1));
}

t_vec3	add_rgb(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res = v_add(a, b);
	return (clamp(&res, 0, 1));
}

t_vec3	scale_rgb(t_vec3 a, double s)
{
	t_vec3	res;

	res = v_scale(a, s);
	return (clamp(&res, 0, 1));
}

int	rgb_to_int(t_vec3 color)
{
	int		rgb;
	t_vec3	clamped;

	clamped = clamp(&color, 0, 1);
	rgb = (int)(clamped.x * 255);
	rgb = (rgb << 8) + (int)(clamped.y * 255);
	rgb = (rgb << 8) + (int)(clamped.z * 255);
	return (rgb);
}
