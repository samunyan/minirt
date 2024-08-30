/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:25:11 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:25:13 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insertion_sort(int a[], int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0 && a[j] < a[j - 1])
		{
			ft_swap(&a[j], &a[j - 1]);
			j++;
		}
		i++;
	}
}
