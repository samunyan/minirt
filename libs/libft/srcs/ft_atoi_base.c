/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:21:54 by samunyan          #+#    #+#             */
/*   Updated: 2022/10/26 14:21:57 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_number_as_str(int n, const char *base, char *res, \
								size_t res_size)
{
	size_t	len;
	size_t	radix;
	long	nb;

	nb = n;
	if (n < 0)
		nb = -nb;
	radix = ft_strlen(base);
	len = ft_get_num_len(nb, radix);
	ft_bzero(res, res_size);
	if (nb == 0)
	{
		len--;
		res[len] = '0';
	}
	if (nb < 0)
		res[0] = '-';
	while (nb > 0)
	{
		len--;
		res[len] = base[nb % radix];
		nb /= radix;
	}
}

static char	*skip_zero(const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp == '0')
		tmp++;
	return (tmp);
}

int	ft_atoi_base_is_valid(int i, const char *str, const char *base)
{
	char	check[33];
	char	*tmp;
	int		is_negative;
	size_t	n;

	get_number_as_str(i, base, check, 33);
	str = ft_skip_space(str);
	is_negative = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	tmp = (char *)str;
	str = skip_zero(str);
	n = 0;
	while (*(str + n) && ft_strchr(base, *(str + n)))
		n++;
	if (n == 0)
		return (i == 0 && *tmp == *base);
	if (is_negative)
		return (!ft_strncmp(str, check + 1, n));
	return (!ft_strncmp(str, check, n));
}

static int	is_valid_base(const char *base)
{
	if (ft_strlen(base) < 2)
		return (0);
	while (*base)
	{
		if (*base == '\t' || *base == '\n' || *base == '\v' || *base == '\f'
			|| *base == '\r' || *base == ' ' || *base == '+' || *base == '-'
			|| ft_strchr(base + 1, *base) != NULL)
			return (0);
		base++;
	}
	return (1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	long	nb;
	int		sign;
	int		radix;

	if (!is_valid_base(base))
		return (0);
	radix = ft_strlen(base);
	str = ft_skip_space(str);
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (*str && ft_strchr(base, *str) != NULL)
	{
		nb = nb * radix + ft_strchr(base, *str) - base;
		str++;
	}
	nb *= sign;
	return ((int)nb);
}
