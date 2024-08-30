/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr_until.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:30:47 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 17:30:50 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr_until(void **arr, size_t i)
{
	while (i)
	{
		free(arr[i]);
		i--;
	}
	free(arr[i]);
	free(arr);
	return (NULL);
}
