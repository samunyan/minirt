/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:17:51 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:17:56 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lis(int a[], int n)
{
	int	*len_arr;
	int	max_len;

	len_arr = ft_get_len_of_increasing_sequences(a, n);
	if (!len_arr)
		return (0);
	max_len = ft_get_len_of_lis(len_arr, n);
	free(len_arr);
	return (max_len);
}

static int	*ft_get_lis_helper(int a[], int n, int *len_arr, int max_len)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * (max_len + 1));
	if (!lis)
		return (NULL);
	lis[0] = max_len;
	i = ft_get_end_index_of_lis(n, len_arr);
	lis[max_len] = a[i];
	j = i - 1;
	while (j >= 0)
	{
		if (a[j] < a[i] && len_arr[j] == len_arr[i] - 1)
		{
			i = j;
			max_len--;
			lis[max_len] = a[i];
		}
		j--;
	}
	return (lis);
}

int	*ft_get_lis(int a[], int n)
{
	int	*lis;
	int	*len_arr;
	int	max_len;

	len_arr = ft_get_len_of_increasing_sequences(a, n);
	if (!len_arr)
		return (NULL);
	max_len = ft_get_len_of_lis(len_arr, n);
	lis = ft_get_lis_helper(a, n, len_arr, max_len);
	free(len_arr);
	return (lis);
}
