/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:41:51 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 17:41:52 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*res;
	size_t	len;

	if (ft_strlen(s2) < n)
		n = ft_strlen(s2);
	len = ft_strlen(s1) + n;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (*s1)
	{
		*res = *s1;
		res++;
		s1++;
	}
	while (n)
	{
		*res = *s2;
		res++;
		s2++;
		n--;
	}
	*res = '\0';
	return (res - len);
}
