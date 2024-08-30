/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:34:40 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 17:34:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prepend(char **dst, const char *src)
{
	char	*tmp;

	if (!(*dst))
		*dst = ft_strdup(src);
	else
	{
		tmp = ft_strjoin(src, *dst);
		free(*dst);
		*dst = tmp;
	}
	return (*dst);
}
