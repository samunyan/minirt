/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:18:39 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:18:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	long	nb;

	nb = n;
	if (n < 0)
		nb = -nb;
	i = ft_get_num_len(nb, 10);
	if (n < 0)
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n < 0)
		s[0] = '-';
	while (nb >= 0)
	{
		i--;
		s[i] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0)
			break ;
	}
	return (s);
}

char	*ft_utoa(unsigned int n)
{
	char	*s;
	size_t	i;

	i = ft_get_num_len(n, 10);
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n == 0)
	{
		i--;
		s[i] = '0';
	}
	while (n > 0)
	{
		i--;
		s[i] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_ltoa(long n)
{
	char		*s;
	size_t		i;
	long long	nb;

	nb = n;
	if (n < 0)
		nb = -nb;
	i = ft_get_num_len(nb, 10);
	if (n < 0)
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n < 0)
		s[0] = '-';
	while (nb >= 0)
	{
		i--;
		s[i] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0)
			break ;
	}
	return (s);
}
