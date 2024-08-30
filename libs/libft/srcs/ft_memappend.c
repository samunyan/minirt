/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:41:18 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/28 21:41:20 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memappend(void **dst, const void *src, size_t dstsize,
			size_t srcsize)
{
	void	*tmp;

	if (!(*dst))
	{
		*dst = malloc(srcsize);
		if (!(*dst))
			return (NULL);
		*dst = ft_memmove(*dst, src, srcsize);
	}
	else
	{
		tmp = malloc(dstsize + srcsize);
		if (tmp)
		{
			ft_memmove(tmp, *dst, dstsize);
			ft_memmove(tmp + dstsize, src, srcsize);
		}
		free(*dst);
		*dst = tmp;
	}
	return (*dst);
}
