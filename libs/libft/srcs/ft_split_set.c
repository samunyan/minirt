/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:18:19 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:18:28 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_in_set(char c, char const *set)
{
	return (ft_strchr(set, c));
}

static size_t	count_tokens(char const *s, char const *set)
{
	size_t	count;
	size_t	i;

	i = 0;
	if (!s[i])
		return (0);
	count = 0;
	while (s[i])
	{
		if (!is_in_set(s[i], set))
			count++;
		while (!is_in_set(s[i], set) && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (count);
}

static size_t	get_token_len(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_in_set(s[i], set))
		i++;
	return (i);
}

char	**ft_split_set(char const *s, char const *set)
{
	char	**arr;
	size_t	n_tokens;
	size_t	i;
	size_t	len;

	n_tokens = count_tokens(s, set);
	arr = malloc(sizeof(arr) * (n_tokens + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < n_tokens)
	{
		while (*s && is_in_set(*s, set))
			s++;
		len = get_token_len(s, set);
		arr[i] = ft_strndup(s, len);
		if (!arr[i])
			return (ft_free_arr_until((void **)arr, i));
		s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
