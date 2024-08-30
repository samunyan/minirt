/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:12:38 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:12:40 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*dst;

	slen = ft_strlen(s);
	if (start + len > slen)
		len = slen - start;
	if (start >= slen)
		len = 0;
	else
		s += start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (len && s[i])
	{
		dst[i] = s[i];
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
