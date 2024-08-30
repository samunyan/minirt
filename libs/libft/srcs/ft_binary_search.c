/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:25:25 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:25:28 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_binary_search(int *arr, int size, int n)
{
	int	low;
	int	high;
	int	mid;
	int	guess;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = arr[mid];
		if (guess == n)
			return (mid);
		if (guess > n)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}
