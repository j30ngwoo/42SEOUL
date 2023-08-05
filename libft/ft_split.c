/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:06:05 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 15:36:51 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static size_t	part_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static	char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*result;

	result = ft_calloc(n + 1, sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static	char	**free_all(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != 0)
		free(result[i++]);
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	result_index;

	result = ft_calloc(count_strings(s, c) + 1, sizeof(char *));
	if (result == 0)
		return (0);
	result_index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			result[result_index] = ft_strndup(s, part_len(s, c));
			if (result[result_index++] == 0)
				return (free_all(result));
			s += part_len(s, c);
		}
	}
	result[result_index] = 0;
	return (result);
}
