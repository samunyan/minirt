/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:25:43 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:25:59 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_int_arr_to(int a[], int n, int val)
{
	int	i;

	i = 0;
	while (i < n)
	{
		a[i] = val;
		i++;
	}
}

int	*ft_get_len_of_increasing_sequences(int a[], int n)
{
	int	*len_arr;
	int	i;
	int	j;

	len_arr = malloc(sizeof(int) * n);
	if (!len_arr)
		return (NULL);
	set_int_arr_to(len_arr, n, 1);
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[j] > a[i])
				len_arr[j] = ft_max(len_arr[j], len_arr[i] + 1);
			j++;
		}
		i++;
	}
	return (len_arr);
}

int	ft_get_len_of_lis(int len_arr[], int n)
{
	int	max_len;
	int	i;

	max_len = 0;
	i = 0;
	while (i < n)
	{
		max_len = ft_max(max_len, len_arr[i]);
		i++;
	}
	return (max_len);
}

int	ft_get_end_index_of_lis(int n, int len_arr[])
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = i;
	max = len_arr[i];
	while (i < n)
	{
		if (len_arr[i] > max)
		{
			max = len_arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}
