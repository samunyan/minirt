/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:39:29 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 13:39:30 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst > src)
	{
		i = len - 1;
		while (i + 1)
		{
			*((unsigned char *)(dst + i)) = *((const unsigned char *)(src + i));
			i--;
		}
	}
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)(dst + i)) = *((const unsigned char *)(src + i));
			i++;
		}
	}
	return (dst);
}
