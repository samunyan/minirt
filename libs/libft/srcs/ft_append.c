/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:34:40 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 17:34:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_until(char **dst, const char *src, size_t n)
{
	char	*tmp;

	if (!(*dst))
		*dst = ft_strndup(src, n);
	else
	{
		tmp = ft_strnjoin(*dst, src, n);
		free(*dst);
		*dst = tmp;
	}
	return (*dst);
}

char	*ft_append(char **dst, const char *src)
{
	char	*tmp;

	if (!(*dst))
		*dst = ft_strdup(src);
	else
	{
		tmp = ft_strjoin(*dst, src);
		free(*dst);
		*dst = tmp;
	}
	return (*dst);
}
