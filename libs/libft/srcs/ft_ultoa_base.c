/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:18:39 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:18:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_num_len(unsigned long long n, unsigned int radix)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= radix;
	}
	return (i);
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	char	*s;
	size_t	len;
	size_t	radix;

	radix = ft_strlen(base);
	len = ft_get_num_len(n, radix);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
	{
		len--;
		s[len] = '0';
	}
	while (n > 0)
	{
		len--;
		s[len] = base[n % radix];
		n /= radix;
	}
	return (s);
}

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	char	*s;
	size_t	len;
	size_t	radix;

	radix = ft_strlen(base);
	len = ft_get_num_len(n, radix);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
	{
		len--;
		s[len] = '0';
	}
	while (n > 0)
	{
		len--;
		s[len] = base[n % radix];
		n /= radix;
	}
	return (s);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char	*s;
	size_t	len;
	size_t	radix;

	radix = ft_strlen(base);
	len = ft_get_num_len(n, radix);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
	{
		len--;
		s[len] = '0';
	}
	while (n > 0)
	{
		len--;
		s[len] = base[n % radix];
		n /= radix;
	}
	return (s);
}
