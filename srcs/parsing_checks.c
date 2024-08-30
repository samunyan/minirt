/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:15:33 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:49:44 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_file_name(const char *filepath)
{
	int	row;

	row = 1;
	while (filepath[row] && filepath[row] != '.')
		row++;
	if (filepath[row + 1] != 'r' || filepath[row + 2] != 't'
		|| filepath[row + 3] != '\0')
		return (false);
	return (true);
}

int	double_is_in_range(double d, double min, double max)
{
	return (min <= d && d <= max);
}

int	vec3_is_in_range(t_vec3 *v, double min, double max)
{
	return (double_is_in_range(v->x, min, max)
		&& double_is_in_range(v->y, min, max)
		&& double_is_in_range(v->z, min, max)
		&& !(v->x == 0 && v->y == 0 && v->z == 0));
}

int	str_contains_double(const char *str)
{
	str = ft_skip_space(str);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '.' && *str)
	{
		if (!ft_isdigit(*str) && *str != '\n')
			return (false);
		str++;
	}
	if (*str == '.')
		str++;
	if (!ft_isdigit(*str) && *str != '\n' && *str != '\0')
		return (false);
	while ('0' <= *str && *str <= '9')
	{
		str++;
		if (!ft_isdigit(*str) && *str != '\n' && *str != '\0')
			return (false);
	}
	return (true);
}

int	str_contains_int(const char *str)
{
	str = ft_skip_space(str);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '\n')
			return (false);
		str++;
	}
	return (true);
}
