/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:01:24 by samunyan          #+#    #+#             */
/*   Updated: 2023/05/31 15:38:21 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *str)
{
	double	val;
	double	sign_exp;

	str = ft_skip_space(str);
	sign_exp = 1;
	if (*str == '-')
		sign_exp = -1;
	if (*str == '-' || *str == '+')
		str++;
	val = 0;
	while ('0' <= *str && *str <= '9')
	{
		val = val * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		val = val * 10 + (*str - '0');
		sign_exp *= 10;
		str++;
	}
	return (val / sign_exp);
}
