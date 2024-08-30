/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:25:01 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:25:04 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_selection_sort(int a[], int n)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < n)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (a[j] < a[min])
				min = j;
			j++;
		}
		ft_swap(&a[i], &a[min]);
		i++;
	}
}
