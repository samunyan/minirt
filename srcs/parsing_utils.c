/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:15:10 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 13:47:09 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	arrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	strarr_is_valid(char **data, int ints_in_str)
{
	if (ints_in_str)
		return (str_contains_int(data[0]) && str_contains_int(data[1])
			&& str_contains_int(data[2]));
	else
		return (str_contains_double(data[0]) && str_contains_double(data[1])
			&& str_contains_double(data[2]));
}

static int	mrt_atof_is_valid(double f, char *s)
{
	char	*tmp;
	size_t	len;

	tmp = ft_strchr(s, '.');
	if (tmp)
		*tmp = '\0';
	len = ft_strlen(s);
	return (len > 0 && len < 12 && ft_atoi_is_valid((int)f, s));
}

int	str_to_3_doubles(char *src, t_vec3 *dst, int ints_in_str)
{
	char	**data;
	int		ret;

	if (src[ft_strlen(src) - 1] == ',')
		return (false);
	data = ft_split(src, ',');
	if (!data)
		return (mrt_error(strerror, errno, "str_to_3_doubles"));
	if (arrlen(data) == 3 && strarr_is_valid(data, ints_in_str))
	{
		dst->x = ft_atof(data[0]);
		dst->y = ft_atof(data[1]);
		dst->z = ft_atof(data[2]);
		if (!mrt_atof_is_valid(dst->x, data[0])
			|| !mrt_atof_is_valid(dst->y, data[1])
			|| !mrt_atof_is_valid(dst->z, data[2]))
			ret = false;
		else
			ret = true;
	}
	else
		ret = false;
	ft_free_arr((void **)data);
	return (ret);
}

int	str_to_1_double(char *src, double *dst, int int_int_str)
{
	if (int_int_str && !str_contains_int(src))
		return (false);
	if (!str_contains_double(src))
		return (false);
	*dst = ft_atof(src);
	return (mrt_atof_is_valid(*dst, src));
}
