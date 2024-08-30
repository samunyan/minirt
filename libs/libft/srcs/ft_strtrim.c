/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:17:54 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:17:55 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	size_t		len;

	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	if (!*s1)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	start = s1;
	while (*s1)
		s1++;
	while (ft_strchr(set, *(s1 - 1)) != NULL)
		s1--;
	len = s1 - start;
	return (ft_substr(start, 0, len));
}
